/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:01:25 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/12 20:10:43 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        draw_img(t_map *map)
{
    mlx_clear_window(map->mlx_ptr, map->win_ptr);
    mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
}

void        clear_img(t_map *map)
{
    size_t y;
    size_t x;

    y = UINT64_MAX;
    while (++y < HEIGHT)
    {
        x = UINT64_MAX;
        while (++x < WIDTH)
        {
            map->buf[y * WIDTH + x] = 0x0;
        }
    }
}

void        pixel_to_buf(int *buf, int x, int y, int color)
{
    if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
            buf[y * WIDTH + x] = color;
}

void		draw_map(t_map *map)
{
	size_t y;
	size_t x;

	y = UINT64_MAX;
//	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	while (++y < map->height)
	{
		x = UINT64_MAX;
		while (++x < map->width)
		{
            pixel_to_buf(map->buf,
				map->coord[y][x].pos.x * map->zoom.x + map->move.x,
				(map->coord[y][x].pos.y * map->zoom.y + map->move.y
				- (map->coord[y][x].pos.z * map->zoom.z)),
		    	map->coord[y][x].color);
		}
	}
}

