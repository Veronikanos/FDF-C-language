/*                                                                            */
/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <vtlostiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:21:16 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:07 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec3		rotate_z(t_vec3 px, double angle)
{
	return ((t_vec3){ px.x * cos(angle) - px.y * sin(angle),
						px.x * sin(angle) + px.y * cos(angle),
						px.z });
}

static t_vec3		rotate_y(t_vec3 px, double angle)
{
	return ((t_vec3){ px.x * cos(angle) + px.z * sin(angle),
						px.y,
						-px.x * sin(angle) + px.z * cos(angle) });
}

static t_vec3		rotate_x(t_vec3 px, double angle)
{
	return ((t_vec3){ px.x,
						px.y * cos(angle) + px.z * sin(angle),
						-px.y * sin(angle) + px.z * cos(angle) });
}

static void 	rotate_map(t_map *map, int i)
{
	int y;
	int x;

	y = -1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	while (++y < map->heigth)
	{
		x = -1;
		while (++x < map->width)
		{
			if (i == 6)
				map->coord[y][x].pos = rotate_x(map->coord[y][x].pos, ANGLE);
			else if (i == 5)
				map->coord[y][x].pos = rotate_x(map->coord[y][x].pos, -ANGLE);
			else if (i == 3)
				map->coord[y][x].pos = rotate_y(map->coord[y][x].pos, ANGLE);
			else if (i == 2)
				map->coord[y][x].pos = rotate_y(map->coord[y][x].pos, -ANGLE);
			else if (i == 9)
				map->coord[y][x].pos = rotate_z(map->coord[y][x].pos, ANGLE);
			else if (i == 8)
				map->coord[y][x].pos = rotate_z(map->coord[y][x].pos, -ANGLE);
		}
	}

}

int kb_press_key(int key, t_map *map)
{
	int		k_num;

	if (key == ESC)
		exit(0);
	if (key == LEFT_ARROW)
		map->move.x -= 10;
	if (key == RIGHT_ARROW)
		map->move.x += 10;
	if (key == UP_ARROW)
		map->move.y -= 10;
	if (key == DOWN_ARROW)
		map->move.y += 10;
	if (key == PLUS)
		map->zoom.z += ZOOMZ;
	if (key == MINUS)
		map->zoom.z -= ZOOMZ;
	if ((key == SIX && (k_num = 6))
	|| (key == FIVE && (k_num = 5))
	|| (key == THREE && (k_num = 3))
	|| (key == TWO && (k_num = 2))
	|| (key == NINE && (k_num = 9))
	|| (key == EIGHT && (k_num = 8)))
		rotate_map(map, k_num);
	draw_map(map);
	return (0);
}

int mouse_scroll(int key, int x, int y, t_map *map)
{
	x = x + 1;
	y = y + 1;

	if (key == MOUSE_UP && map->zoom.x < 142 && map->zoom.y < 142)
	{
		map->zoom.x += 1;
		map->zoom.y += 1;
		map->zoom.z += 1;
	}
	if (key == MOUSE_DOWN && map->zoom.x > 2 && map->zoom.y > 2)
	{
		map->zoom.x -= 1;
		map->zoom.y -= 1;
		map->zoom.z -= 1;
	}
	draw_map(map);
	return (0);
}

static t_map	*alignment(t_map *map)
{
	map->move.x -= map->width / 2 * map->zoom.x;
	map->move.y -= map->heigth / 2 * map->zoom.y;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, NAME);
	return (map);
}

static t_map	*init(t_map *map)
{
	if (!map)
		return (NULL);
	map->width = 0;
	map->heigth = 0;
	map->zoom = (t_vec3){ 20, 20, 20 };
	map->move = (t_vec2){ HALF_WIDTH, HALF_HEIGHT };
	return (map);
}

int main(int argc, char **argv)
{
	t_map 	*map;
	t_lines *lines_head;

	lines_head = NULL;
	if (argc != 2)
		errors_msg(2);
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		errors_msg(4);
	init(map);
	map->fd = open(argv[1], O_RDONLY);
	is_file_valid(map, &lines_head);
	parsing(map, lines_head);
	close(map->fd);

	alignment(map);
	draw_map(map);
	mlx_hook(map->win_ptr, 2, 5, kb_press_key, map);
	mlx_mouse_hook(map->win_ptr, mouse_scroll, map);

	mlx_loop(map->mlx_ptr);

	system("leaks -q fdf");
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
//	ft_putstr("Usage: ./fdf map.fdf\n");
	return (0);
}


