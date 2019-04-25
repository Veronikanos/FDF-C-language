/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:50:29 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/25 18:23:33 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		move_to_x(int len, t_map *map, int color, int d)
{
	d = -(map->length.x);
	len++;
	while (len--)
	{
		pixel_to_buf(map->buf, map, map->point, color);
		map->point.x += map->d_xy.x;
		d += 2 * map->length.y;
		if (d > 0)
		{
			d -= 2 * map->length.x;
			map->point.y += map->d_xy.y;
		}
	}
}

static void		move_to_y(int len, t_map *map, int color, int d)
{
	d = -(map->length.y);
	len++;
	while (len--)
	{
		pixel_to_buf(map->buf, map, map->point, color);
		map->point.y += map->d_xy.y;
		d += 2 * map->length.x;
		if (d > 0)
		{
			d -= 2 * map->length.y;
			map->point.x += map->d_xy.x;
		}
	}
}

void			bresenham(t_map *map, t_draw s, t_draw e, int color)
{
	int len;
	int	d;

	map->d_xy = (t_draw){ (e.x - s.x >= 0 ? 1 : -1),
						(e.y - s.y >= 0 ? 1 : -1) };
	map->length.x = (e.x - s.x) < 0 ? (e.x - s.x) * -1 : (e.x - s.x) * 1;
	map->length.y = (e.y - s.y) < 0 ? (e.y - s.y) * -1 : (e.y - s.y) * 1;
	len = (map->length.x > map->length.y ? map->length.x : map->length.y);
	if (len == 0)
		pixel_to_buf(map->buf, map, (t_draw) { s.x, s.y }, color);
	map->point = (t_draw) { s.x, s.y };
	if (map->length.y <= map->length.x)
		move_to_x(len, map, color, d);
	else
		move_to_y(len, map, color, d);
}
