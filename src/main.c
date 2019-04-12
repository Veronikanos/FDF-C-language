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

static t_vec3	reset_zoom(void)
{
	return ((t_vec3){ 20, 20, 20 });
}

static t_vec2	alignment(size_t width, size_t height, t_vec3 zoom)
{
	return ((t_vec2){ (HALF_WIDTH - width / 2.0 * zoom.x),
					  (HALF_HEIGHT - height / 2.0 * zoom.y) });
}

void	reset_img(t_map *map)
{
	size_t		y;
	size_t		x;

	y = UINT64_MAX;
	while (++y < map->height)
	{
		x = UINT64_MAX;
		while (map->width > ++x)
		{
			map->coord[y][x].pos.x = x;
			map->coord[y][x].pos.y = y;
			map->coord[y][x].pos.z = map->coord[y][x].z_orig;
		}
	}
	map->zoom = reset_zoom();
	map->move = alignment(map->width, map->height, map->zoom);
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
		map->zoom.z /= ZOOMZ;
	if (key == MINUS)
		map->zoom.z *= ZOOMZ;
	if (key == R)
		reset_img(map);
	if ((key == SIX && (k_num = 6) && map->angle.x *ANGLE)
	|| (key == FIVE && (k_num = 5))
	|| (key == THREE && (k_num = 3))
	|| (key == TWO && (k_num = 2))
	|| (key == NINE && (k_num = 9))
	|| (key == EIGHT && (k_num = 8)))
		rotate_map(map, k_num);
	draw_map(map);
    draw_img(map);
    clear_img(map);
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

static t_map	*init(t_map *map)
{
	if (!map)
		return (NULL);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, NAME);
	map->width = 0;
	map->height = 0;
	map->img_ptr = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	map->buf = (int *)mlx_get_data_addr(map->img_ptr, &map->bits_per_pixel, &map->size_line, &map->endian);
	map->zoom = reset_zoom();
	map->angle.x = 0;
	map->angle.y = 0;
	map->angle.z = 0;
	return (map);
}

int main(int argc, char **argv)
{
	t_map	*map;
	t_lines	*lines_head;

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

	map->move = alignment(map->width, map->height, map->zoom);
	draw_map(map);
    draw_img(map);
    clear_img(map);
	mlx_hook(map->win_ptr, 2, 5, kb_press_key, map);
	mlx_mouse_hook(map->win_ptr, mouse_scroll, map);



	mlx_loop(map->mlx_ptr);

	system("leaks -q fdf");
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
//	ft_putstr("Usage: ./fdf map.fdf\n");
	return (0);
}


