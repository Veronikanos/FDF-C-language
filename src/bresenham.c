/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:50:29 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/24 17:51:08 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void     first_way(int len, t_map *map, int color, int d)
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

static void     second_way(int len, t_map *map, int color, int d)
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

void            bresenham(t_map *map, t_draw s, t_draw e, int color)
{
    int    len;
    int    d;

    map->d_xy = (t_draw){ (e.x - s.x >= 0 ? 1 : -1),
                          (e.y - s.y >= 0 ? 1 : -1) };
    map->length.x = (e.x - s.x) < 0 ? (e.x - s.x) * -1 : (e.x - s.x) * 1;
    map->length.y = (e.y - s.y) < 0 ? (e.y - s.y) * -1 : (e.y - s.y) * 1;
    len = (map->length.x - map->length.y > 0 ? map->length.x : map->length.y);
    if (len == 0)
        pixel_to_buf(map->buf, map, map->d_xy, color);
    map->point = (t_draw) { s.x, s.y };
    if (map->length.y <= map->length.x)
        first_way(len, map, color, d);
    else
        second_way(len, map, color, d);
}