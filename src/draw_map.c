/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:01:25 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/18 21:00:16 by vtlostiu         ###   ########.fr       */
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

void        pixel_to_buf(int *buf, int x, int y, int color)
{
    if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
            buf[y * WIDTH + x] = color;
}

void		draw_map(t_map *map)
{
	size_t y;
	size_t x;
    t_vec3 curr;

	y = UINT64_MAX;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
 //   map->move = alignment(map->width, map->height, map->zoom); //вынесено с main
	while (++y < map->height)
	{
		x = UINT64_MAX;
		while (++x < map->width)
		{
            curr = map->coord[y][x].pos;
//		    right = map->coord[y][x + 1].pos;
//            down = map->coord[y + 1][x].pos;

            curr.x -= H_WIDTH;
            curr.y -= H_HEIGHT;
		    curr.x *= map->zoom.x;
            curr.y *= map->zoom.y;
            curr.z *= map->zoom.z;
            curr = rotate(curr, map->angle.x, map->angle.y, map->angle.z);
//            printf("Cord  x = %f, y = %f, z = %f\n", new.x + map->move.x, new.y + map->move.y - (new.z), new.z);

            curr.x += H_WIDTH;
            curr.y += H_HEIGHT ;
            bresenham(map, curr, map->coord[y][x + 1].pos, COLOR);
            bresenham(map, map->coord[y][x].pos, map->coord[y + 1][x].pos, COLOR);
//            pixel_to_buf(map->buf, new.x + map->move.x,
//			           	new.y + map->move.y - new.z,
//		                map->coord[y][x].color);
		}
	}
}

