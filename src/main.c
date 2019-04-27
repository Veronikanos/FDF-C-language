/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:21:16 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/25 20:48:14 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2			alignment(size_t width, size_t height)
{
	return ((t_vec2){ HALF_WIDTH - width / 2.0,
					HALF_HEIGHT - height / 2.0 });
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
	map->buf = (int *)mlx_get_data_addr(map->img_ptr, &map->bits_per_pixel,
			&map->size_line, &map->endian);
	map->zoom = reset_zoom();
	map->angle.x = 0;
	map->angle.y = 0;
	map->angle.z = 0;
	return (map);
}

int				main(int argc, char **argv)
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
	if (read(map->fd, NULL, 0))
		errors_msg(6);
	is_file_valid(map, &lines_head);
	parsing(map, lines_head);
	close(map->fd);
	map->move = alignment(map->width, map->height);
	draw_screen(map);
	mlx_hook(map->win_ptr, 2, 5, kb_press_key, map);
	mlx_mouse_hook(map->win_ptr, mouse_scroll, map);
	mlx_hook(map->win_ptr, 17, 1L << 17, errors_msg, NULL);
	mlx_loop(map->mlx_ptr);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	return (0);
}
