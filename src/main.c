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


int press_key(int key, t_map *map)
{
	if (key == ESC)
		exit(0);
	//mlx_pixel_put(mlx_ptr, win_ptr, )
	return (0);
}

int main(int argc, char **argv)
{
	t_map 	*map;
	t_lines *lines_head;
	void	*mlx_ptr;
	void	*win_ptr;

	lines_head = NULL;
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		errors_msg(4);
	map->width = 0;
	map->heigth = 0;

	if (argc != 2)
		errors_msg(2);
	map->fd = open(argv[1], O_RDONLY);
	is_file_valid(map, &lines_head);
	parsing(map, lines_head);
	close(map->fd);


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, NAME);
//	win_ptr = mlx_new_window(mlx_ptr, 500, 500, NAME);
//	mlx_pixel_put(mlx_ptr, win_ptr, WIDTH / 2, HEIGHT / 2, 0xFF0000);

	int y = -1;
	while (++y < map->heigth)
	{
		int x = -1;
		while (++x < map->width)
		{
			mlx_pixel_put(mlx_ptr, win_ptr,
					(map->coord[y][x].x * 20 + (WIDTH / 2 - 200)),
					((map->coord[y][x].y - map->coord[y][x].z) * 20 + HEIGHT / 2),
					0xFF0000);
		}
	}


	mlx_key_hook(win_ptr, press_key, (void *)0);
	mlx_loop(mlx_ptr);

	system("leaks -q fdf");

//	ft_putstr("Usage: ./fdf map.fdf\n");
	return (0);
}


