/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:01:25 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/14 15:54:44 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        draw_img(t_map *map)
{
    mlx_clear_window(map->mlx_ptr, map->win_ptr);
    mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
 //   clear_img(map);
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
    t_vec3 new;
	y = UINT64_MAX;
//	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	while (++y < map->height)
	{
		x = UINT64_MAX;
		while (++x < map->width)
		{
		    new = map->coord[y][x].pos;
		    new.x *= map->zoom.x;
            new.y *= map->zoom.y;
            new.z *= map->zoom.z;
//			new.x -= map->width / 2;
//			new.y -= map->height / 2;
            new = rotate_z(map, rotate_y(map, rotate_x(map, new, map->angle.x), map->angle.y), map->angle.z);
//            new.x += map->width / 2;
//            new.y += map->height / 2;
            pixel_to_buf(map->buf, new.x + map->move.x,
				(new.y + map->move.y - (new.z)),
		    	map->coord[y][x].color);
		}
	}
}

