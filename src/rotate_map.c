/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:19:12 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/14 15:58:32 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3		rotate_z(t_map *map, t_vec3 px, double angle)
{
//	px.x -= map->width / 2;
//	px.y -= map->height / 2;
	px = (t_vec3){ px.x * cos(angle) - px.y * sin(angle),
					   px.x * sin(angle) + px.y * cos(angle),
					   px.z };
//	px.x += map->width / 2;
//	px.y += map->height / 2;
	return (px);
}

t_vec3		rotate_y(t_map *map, t_vec3 px, double angle)
{
//	px.x -= map->width / 2;
//	px.y -= map->height / 2;
	px = (t_vec3){ px.x * cos(angle) + px.z * sin(angle),
				   px.y,
				   -px.x * sin(angle) + px.z * cos(angle) };
//	px.x += map->width / 2;
//	px.y += map->height / 2;
	return (px);
}

t_vec3		rotate_x(t_map *map, t_vec3 px, double angle)
{
//	px.x -= map->width / 2;
//	px.y -= map->height / 2;
	px = (t_vec3){ px.x,
				   px.y * cos(angle) + px.z * sin(angle),
				   -px.y * sin(angle) + px.z * cos(angle) };
//	px.x += map->width / 2;
//	px.y += map->height / 2;
	return (px);
}

void 	rotate_map(t_map *map, int i)
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
//			map->coord[y][x].pos.x -= map->width / 2;
//			map->coord[y][x].pos.y -= map->height / 2;
			if (i == 6)
				map->angle.x += RAD;
			else if (i == 5)
				map->angle.x -= RAD;
			else if (i == 3)
				map->angle.y += RAD;
			else if (i == 2)
				map->angle.y -= RAD;
			else if (i == 9)
				map->angle.z += RAD;
			else if (i == 8)
				map->angle.z -= RAD;
//			map->coord[y][x].pos.x += map->width / 2;
//			map->coord[y][x].pos.y += map->height / 2;
		}
	}
}