/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <vtlostiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:19:12 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/11 15:02:48 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec3		rotate_z(t_vec3 px, double angle) //, t_angle a)
{
//	a.z += 10;

	return ((t_vec3){ px.x * cos(angle) - px.y * sin(angle),
					  px.x * sin(angle) + px.y * cos(angle),
					  px.z });
}

static t_vec3		rotate_y(t_vec3 px, double angle) //, t_angle a)
{
//	a.y += 10;

	return ((t_vec3){ px.x * cos(angle) + px.z * sin(angle),
					  px.y,
					  -px.x * sin(angle) + px.z * cos(angle) });
}

static t_vec3		rotate_x(t_vec3 px, double angle) //, t_angle a)
{
//	 a.x++;

	return ((t_vec3){ px.x,
					  px.y * cos(angle) + px.z * sin(angle),
					  -px.y * sin(angle) + px.z * cos(angle) });
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
			map->coord[y][x].pos.x -= map->width / 2;
			map->coord[y][x].pos.y -= map->height / 2;
		//	map->coord

		// третий аргумент*??????
			if (i == 6)
				map->coord[y][x].pos = rotate_x(map->coord[y][x].pos, map->angle.x);
			else if (i == 5)
				map->coord[y][x].pos = rotate_x(map->coord[y][x].pos, -map->angle.x);//, map->angle);
			else if (i == 3)
				map->coord[y][x].pos = rotate_y(map->coord[y][x].pos, map->angle.y);//, map->angle);
			else if (i == 2)
				map->coord[y][x].pos = rotate_y(map->coord[y][x].pos, -map->angle.y);//, map->angle);
			else if (i == 9)
				map->coord[y][x].pos = rotate_z(map->coord[y][x].pos, map->angle.z);//, map->angle);
			else if (i == 8)
				map->coord[y][x].pos = rotate_z(map->coord[y][x].pos, -map->angle.z);//, map->angle);
			map->coord[y][x].pos.x += map->width / 2;
			map->coord[y][x].pos.y += map->height / 2;
		}
	}
}