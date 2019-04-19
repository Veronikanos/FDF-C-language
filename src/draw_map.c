/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:01:25 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/19 22:35:16 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        draw_img(t_map *map)
{
    mlx_clear_window(map->mlx_ptr, map->win_ptr);
    mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
 //   clear_img(map);
    mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 30, COLOR,
            "MOVE                arrows: left, right, up, down");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 50, COLOR,
            "SCALE               mouse scroll: up, down");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 70, COLOR,
            "ROTATION            y: 2, 3 | x: 5, 6 | z: 8, 9");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 90, COLOR,
            "INCREASE HEIGHT     +, -");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 110, COLOR,
            "RESET               R");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 130, COLOR,
            "EXIT                ESC");
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

void        pixel_to_buf(int *buf, t_map *map, t_draw px, int color)
{
    px.x += map->move.x;
    px.y += map->move.y;

    if (px.x >= 0 && px.y >= 0 && px.x < WIDTH && px.y < HEIGHT)
            buf[px.y * WIDTH + px.x] = color;
}

static void     classic_style(t_map *map, t_vec3 **rot_map)
{
    t_vec3  beg;
    t_vec3  end;
    size_t  y;
    size_t  x;

    y = UINT64_MAX;
    while (++y < map->height)
    {
        x = UINT64_MAX;
        while (++x < map->width)
        {
            beg = rot_map[y][x];
            end = rot_map[y][x + 1];
            if (x < map->width - 1)
                bresenham(map, (t_draw){ (int)beg.x, (int)beg.y - (int)beg.z },
                               (t_draw){ (int)end.x, (int)end.y - (int)end.z },
                               map->coord[y][x].color);
            end = rot_map[y + 1][x];
            if (y < map->height - 1)
                bresenham(map, (t_draw){ (int)beg.x, (int)beg.y - (int)beg.z },
                               (t_draw){ (int)end.x, (int)end.y - (int)end.z },
                               map->coord[y][x].color);
        }
    }
}

void		draw_map(t_map *map)
{
	size_t y;
	size_t x;
    t_vec3 new;

	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	y = UINT64_MAX;
	while (++y < map->height)
	{
		x = UINT64_MAX;
		while (++x < map->width)
		{
            new = map->coord[y][x].pos;
            new.x -= H_WIDTH;
            new.y -= H_HEIGHT;
		    new.x *= map->zoom.x;
            new.y *= map->zoom.y;
            new.z *= map->zoom.z;
            new = rotate(new, map->angle.x, map->angle.y, map->angle.z);
            new.x += H_WIDTH;
            new.y += H_HEIGHT;
            map->rot_map[y][x] = new;
		}
	}
	classic_style(map, map->rot_map);
//	y = UINT64_MAX;
//	while (++y < map->height)
//	{
//		x = UINT64_MAX;
//		while (++x < map->width)
//		{
//            if (x < map->width - 1)
//                bresenham(map, (t_draw){ (int)map->rot_map[y][x].x, (int)map->rot_map[y][x].y
//                                                                     - (int)map->rot_map[y][x].z },
//                               (t_draw){ (int)map->rot_map[y][x + 1].x, (int)map->rot_map[y][x + 1].y
//                                                                       - (int)map->rot_map[y][x + 1].z }, map->coord[y][x].color);
//            if (y < map->height - 1)
//                bresenham(map, (t_draw){ (int)map->rot_map[y][x].x, (int)map->rot_map[y][x].y
//                                                                 - (int)map->rot_map[y][x].z },
//                               (t_draw){ (int)map->rot_map[y + 1][x].x, (int)map->rot_map[y + 1][x].y
//                                                                     - (int)map->rot_map[y + 1][x].z }, map->coord[y][x].color);
//		}
//	}

}

