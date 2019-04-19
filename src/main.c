/*                                                                            */
/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <vtlostiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:21:16 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:07 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//
//void    draw_straight(t_draw length, t_draw point, t_draw d_xy)
//{
//    int    d;
//
//}

void    bresenham(t_map *map, t_draw s, t_draw e, int color)
{
    t_draw d_xy;
    t_draw length;
    int    len;
    int    d;

    d_xy = (t_draw){ (e.x - s.x >= 0 ? 1 : -1), (e.y - s.y >= 0 ? 1 : -1) };
    length.x = (e.x - s.x) < 0 ? (e.x - s.x) * -1 : (e.x - s.x) * 1;
    length.y = (e.y - s.y) < 0 ? (e.y - s.y) * -1 : (e.y - s.y) * 1;
    len = (length.x - length.y > 0 ? length.x : length.y);
    if (len == 0)
        pixel_to_buf(map->buf, map, d_xy, color);
    t_draw point = (t_draw) { s.x, s.y };
    if (length.y <= length.x)
    {
        d =-length.x;
        len++;
        while (len--)
        {
            pixel_to_buf(map->buf, map, point, color);
            point.x += d_xy.x;
            d += 2 * length.y;
            if (d > 0)
            {
                d -= 2 * length.x;
                point.y += d_xy.y;
            }
        }
    }
    else
    {
        d = -length.y;
        len++;
        while (len--)
        {
            pixel_to_buf(map->buf, map, point, color);
            point.y += d_xy.y;
            d += 2 * length.x;
            if (d > 0)
            {
                d -= 2 * length.y;
                point.x += d_xy.x;
            }
        }
    }
}

static t_map	*init(t_map *map)
{
	if (!map)
		return (NULL);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, NAME);
	map->width = 0;
	map->height = 0;
	map->img_ptr = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	map->buf = (int *)mlx_get_data_addr(map->img_ptr, &map->bits_per_pixel, &map->size_line, &map->endian);
	map->zoom = reset_zoom();
	map->angle.x = 0;
	map->angle.y = 0;
	map->angle.z = 0;
	return (map);
}

int main(int argc, char **argv)
{
	t_map	*map;
	t_lines	*lines_head;

	lines_head = NULL;
	if (argc != 2)
		errors_msg(2);
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		errors_msg(4);
	init(map);
	map->fd = open(argv[1], O_RDONLY);
	is_file_valid(map, &lines_head);
	parsing(map, lines_head);
	close(map->fd);

	map->move = alignment(map->width, map->height, map->zoom);
//	t_vec2 start    = (t_vec2){ 500, 600 };
//	t_vec2 end      = (t_vec2){ 700, 800 };
//	t_vec2 start2   = (t_vec2){ 800, 600 };
//	t_vec2 end2     = (t_vec2){ 500, 800 };
 //   bresenham(map, start.x, start.y, end.x, end.y, COLOR);
//    bresenham(map, start2.x, start2.y, end2.x, end2.y, COLOR);
//    bresenham(map, 500, 500, 700, 500, COLOR);
	draw_map(map);
    draw_img(map);
    clear_img(map);
	mlx_hook(map->win_ptr, 2, 5, kb_press_key, map);
	mlx_mouse_hook(map->win_ptr, mouse_scroll, map);

	mlx_loop(map->mlx_ptr);

	system("leaks -q fdf");
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
//	ft_putstr("Usage: ./fdf map.fdf\n");
	return (0);
}


