/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:19:12 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/13 21:37:21 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3		rotate_z(t_map *map, t_vec3 px, double angle) //, t_angle a)
{
//	a.z += 10;
	px.x -= map->width / 2;
	px.y -= map->height / 2;
	px = (t_vec3){ px.x * cos(angle) - px.y * sin(angle),
					   px.x * sin(angle) + px.y * cos(angle),
					   px.z };
	px.x += map->width / 2;
	px.y += map->height / 2;
	return (px);
}

t_vec3		rotate_y(t_map *map, t_vec3 px, double angle) //, t_angle a)
{
	px.x -= map->width / 2;
	px.y -= map->height / 2;
	px = (t_vec3){ px.x * cos(angle) + px.z * sin(angle),
				   px.y,
				   -px.x * sin(angle) + px.z * cos(angle) };
	px.x += map->width / 2;
	px.y += map->height / 2;
	return (px);
}


//
//static t_vec3		rotate_y(t_vec3 px, double angle_y, t_vec3 angle)
//{
//    px = ((t_vec3){ px.x * cos(angle_y) + px.z * sin(angle_y),
//					  px.y,
//					  -px.x * sin(angle_y) + px.z * cos(angle_y) });
//    angle.y = angle_y + RAD;
//    return(px);
//}

t_vec3		rotate_x(t_map *map, t_vec3 px, double angle) //, t_angle a)
{
	px.x -= map->width / 2;
	px.y -= map->height / 2;
	px = (t_vec3){ px.x,
				   px.y * cos(angle) + px.z * sin(angle),
				   -px.y * sin(angle) + px.z * cos(angle) };
	px.x += map->width / 2;
	px.y += map->height / 2;
	return (px);
}

//static t_vec3		rotate_x(t_vec3 px, double sum, t_vec3 angle)
//{
//	 px = (t_vec3){ px.x,
//					  px.y * cos(sum) + px.z * sin(sum),
//					  -px.y * sin(sum) + px.z * cos(sum) };
//	angle.x = sum + RAD;
//    return(px);
//}

void 	rotate_map(t_map *map, int i)
{
	int y;
	int x;

	y = -1;
//	reset_2(map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			//map->coord[y][x].pos.x -= map->width / 2;
			//map->coord[y][x].pos.y -= map->height / 2;
			if (i == 6)
				map->angle.x += RAD;
//				map->coord[y][x].pos = rotate_x(map->coord[y][x].pos, ANGLE);
			else if (i == 5)
				map->angle.x -= RAD;
//				map->coord[y][x].pos = rotate_x(map->coord[y][x].pos, -ANGLE);
			else if (i == 3)
				map->angle.y += RAD;
//				map->coord[y][x].pos = rotate_y(map->coord[y][x].pos, ANGLE);
			else if (i == 2)
				map->angle.y -= RAD;
//				map->coord[y][x].pos = rotate_y(map->coord[y][x].pos, -ANGLE);
			else if (i == 9)
				map->angle.z += RAD;
//				map->coord[y][x].pos = rotate_z(map->coord[y][x].pos, ANGLE);
			else if (i == 8)
				map->angle.z -= RAD;
//				map->coord[y][x].pos = rotate_z(map->coord[y][x].pos, -ANGLE);


//			if (i == 6)
//				map->coord[y][x].pos = rotate_x(map->coord[y][x].pos, map->angle.x, map->angle);
//			else if (i == 5)
//				map->coord[y][x].pos = rotate_x(map->coord[y][x].pos, -map->angle.x, map->angle);
//			else if (i == 3)
//				map->coord[y][x].pos = rotate_y(map->coord[y][x].pos, map->angle.y, map->angle);
//			else if (i == 2)
//				map->coord[y][x].pos = rotate_y(map->coord[y][x].pos, -map->angle.y, map->angle);
//			else if (i == 9)
//				map->coord[y][x].pos = rotate_z(map->coord[y][x].pos, map->angle.z);
//			else if (i == 8)
//				map->coord[y][x].pos = rotate_z(map->coord[y][x].pos, -map->angle.z);

			//map->coord[y][x].pos.x += map->width / 2;
			//map->coord[y][x].pos.y += map->height / 2;
		}
	}
}