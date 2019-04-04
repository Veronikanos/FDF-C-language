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
	draw_map(map);
	return (0);
}

int mouse_scroll(int key, int x, int y, t_map *map)
{
	x = x + 1;
	y = y + 1;

	if (key == MOUSE_UP && map->zoom < 142)
		map->zoom += 1;
	if (key == MOUSE_DOWN && map->zoom > 2)
		map->zoom -= 1;
	draw_map(map);
	return (0);
}

static t_map	*init(t_map *map)
{
	if (!map)
		return (NULL);
	map->width = 0;
	map->heigth = 0;
	map->zoom = 20;
	return (map);
}

int main(int argc, char **argv)
{
	t_map 	*map;
	t_lines *lines_head;

	lines_head = NULL;
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		errors_msg(4);
	init(map);
	if (argc != 2)
		errors_msg(2);
	map->fd = open(argv[1], O_RDONLY);
	is_file_valid(map, &lines_head);
	parsing(map, lines_head);
	close(map->fd);

	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, NAME);

	draw_map(map);
	//mlx_key_hook(map->win_ptr, kb_press_key, map);
	mlx_hook(map->win_ptr, 2, 5, kb_press_key, map);
	mlx_mouse_hook(map->win_ptr, mouse_scroll, map);

	mlx_loop(map->mlx_ptr);

	system("leaks -q fdf");
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
//	ft_putstr("Usage: ./fdf map.fdf\n");
	return (0);
}


