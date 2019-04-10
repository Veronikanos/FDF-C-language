/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <vtlostiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:01:25 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/10 19:02:35 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_map(t_map *map)
{
	int y;
	int x;

	y = -1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
				mlx_pixel_put(map->mlx_ptr, map->win_ptr,
				map->coord[y][x].pos.x * map->zoom.x + map->move.x,
				(map->coord[y][x].pos.y * map->zoom.y + map->move.y
				- (map->coord[y][x].pos.z * map->zoom.z)),
			0xFF0000);
		}
	}
}

