/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:01:25 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/13 21:30:18 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        draw_img(t_map *map)
{
    mlx_clear_window(map->mlx_ptr, map->win_ptr);
    mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
  //  clear_img(map);
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
    t_vec3 atata;
	y = UINT64_MAX;
//	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	while (++y < map->height)
	{
		x = UINT64_MAX;
		while (++x < map->width)
		{
		    atata = map->coord[y][x].pos;
		    atata.x *= map->zoom.x;
            atata.y *= map->zoom.y;
            atata.z *= map->zoom.z;
            atata = rotate_z(map, rotate_y(map, rotate_x(map, atata, map->angle.x), map->angle.y), map->angle.z);
            pixel_to_buf(map->buf,
                    atata.x + map->move.x,
				(atata.y + map->move.y
				- (atata.z)),
		    	map->coord[y][x].color);
		}
	}
}

