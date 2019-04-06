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

//void 	rotate_map(t_map *map)
//{
//	// вокруг оси X
//
//	int y;
//	int x;
//
//	y = -1;
////	mlx_clear_window(map->mlx_ptr, map->win_ptr);
//	while (++y < map->heigth)
//	{
//		x = -1;
//		while (++x < map->width)
//		{
//			mlx_clear_window(map->mlx_ptr, map->win_ptr);
//			if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
//
//
//				map->coord[y][x].y = CENTR_Y + (map->coord[y][x].y - CENTR_Y) * cos (map->coord[y][x].y) + (CENTR_Z - map->coord[y][x].z) * 0.1736;
//				map->coord[y][x].z = CENTR_Y + (map->coord[y][x].y - CENTR_Y) * sin (map->coord[y][x].y) + (map->coord[y][x].z - CENTR_Z) * 0.9848;
//
//
//				mlx_pixel_put(map->mlx_ptr, map->win_ptr,
//							  map->coord[y][x].x * map->zoom.x + map->move.x,
//							  (map->coord[y][x].y * map->zoom.y + map->move.y
//							   - (map->coord[y][x].z * map->zoom.z)),
//							  0xFF0000);
//		}
//	}

//	x' = x;
//	y' = y0+(y-y0)*cos(A)+(z0-z)*sin(alpha);
//	z' = z0+(y-y0)*sin(A)+(z-z0)*cos(alpha);
//	 // вокруг оси Y
//	x' = x0+(x-x0)*cos(A)+(z-z0)*sin(alpha);
//	y' = y;
//	z' = z0+(x0-x)*sin(A)+(z-z0)*cos(alpha);
//	 // вокруг оси Z
//	x' = x0+(x-x0)*cos(A)+(y0-y)*sin(alpha);
//	y' = y0+(x-x0)*sin(A)+(y-y0)*cos(alpha);
//	z' = z;

}

int kb_press_key(int key, t_map *map)
{
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
//	if (key == SIX)
//		rotate_map(map);
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
//	rotate_map(map);
	mlx_hook(map->win_ptr, 2, 5, kb_press_key, map);
	mlx_mouse_hook(map->win_ptr, mouse_scroll, map);

	mlx_loop(map->mlx_ptr);

	system("leaks -q fdf");
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
//	ft_putstr("Usage: ./fdf map.fdf\n");
	return (0);
}


