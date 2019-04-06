/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <vtlostiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:01:25 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/06 20:19:05 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_map(t_map *map)
{
	int y;
	int x;

	y = -1;
//	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	while (++y < map->heigth)
	{
		x = -1;
	//	mlx_clear_window(map->mlx_ptr, map->win_ptr);
		while (++x < map->width)
		{
			mlx_clear_window(map->mlx_ptr, map->win_ptr);
			if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
				mlx_pixel_put(map->mlx_ptr, map->win_ptr,
				map->coord[y][x].x * map->zoom.x + map->move.x,
				(map->coord[y][x].y * map->zoom.y + map->move.y
				- (map->coord[y][x].z * map->zoom.z)),
			0xFF0000);
		}
	}
}

