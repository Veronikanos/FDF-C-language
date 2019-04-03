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

int main(int argc, char **argv)
{
//	t_map 	*map;
//	t_lines *lines_head;
	void	*mlx_ptr;
	void	*win_ptr;
//
//	lines_head = NULL;
//	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
//		errors_msg(4);
//	map->width = 0;
//	map->heigth = 0;
//
//	if (argc != 2)
//		errors_msg(2);
//	map->fd = open(argv[1], O_RDONLY);
//	is_file_valid(map, &lines_head);
//	parsing(map, lines_head);
//	close(map->fd);


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, NAME);
	mlx_loop(mlx_ptr);

	system("leaks -q fdf");

//	ft_putstr("Usage: ./fdf map.fdf\n");
	return (0);
}