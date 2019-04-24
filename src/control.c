/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:57:09 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/24 18:01:10 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3          reset_zoom(void)
{
    return ((t_vec3){ 20, 20, 20 });
}

t_vec2	alignment(size_t width, size_t height, t_vec3 zoom)
{
    return ((t_vec2){ HALF_WIDTH - width / 2.0,
                      HALF_HEIGHT - height / 2.0 });
}

static void     reset(t_map *map)
{
    size_t		y;
    size_t		x;

    y = UINT64_MAX;
    while (++y < map->height)
    {
        x = UINT64_MAX;
        while (map->width > ++x)
        {
            map->coord[y][x].pos.x = x;
            map->coord[y][x].pos.y = y;
            map->coord[y][x].pos.z = map->coord[y][x].z_orig;
        }
    }
    map->zoom = reset_zoom();
    map->move = alignment(map->width, map->height, map->zoom);
    map->angle.x = 0;
    map->angle.y = 0;
    map->angle.z = 0;
    draw_map(map);
    draw_img(map);
    clear_img(map);
}

static int      kb_press_angle(int key, t_map *map)
{
    int		k_num;

    if (key == SIX && (k_num = 6))
        map->angle.x += RAD;
    if (key == FIVE && (k_num = 5))
        map->angle.x -= RAD;
    if (key == THREE && (k_num = 3))
        map->angle.y += RAD;
    if (key == TWO && (k_num = 2))
        map->angle.y -= RAD;
    if (key == NINE && (k_num = 9))
        map->angle.z += RAD;
    if (key == EIGHT && (k_num = 8))
        map->angle.z -= RAD;
    return (0);
}

int             kb_press_key(int key, t_map *map)
{
    if (key == ESC)
        exit(0);
    if (key == LEFT_ARROW)
        map->move.x -= 10;
    if (key == RIGHT_ARROW)
        map->move.x += 10;
    if (key == UP_ARROW)
        map->move.y -= 10;
    if (key == DOWN_ARROW)
        map->move.y += 10;
    if (key == PLUS || key == PLUS2)
        map->zoom.z += ZOOMZ;
    if (key == MINUS || key == MINUS2)
        map->zoom.z -= ZOOMZ;
    if (key == R)
        reset(map);
    if (key == SIX || key == FIVE || key == THREE
        || key == TWO || key == NINE || key == EIGHT)
        kb_press_angle(key, map);
    draw_map(map);
    draw_img(map);
    clear_img(map);
    return (0);
}

int             mouse_scroll(int key, int x, int y, t_map *map)
{
    x = x + 1;
    y = y + 1;

    if (key == MOUSE_UP && map->zoom.x < 142 && map->zoom.y < 142)
    {
        map->zoom.x += 1;
        map->zoom.y += 1;
        map->zoom.z += 1;
    }
    if (key == MOUSE_DOWN && map->zoom.x > 2 && map->zoom.y > 2)
    {
        map->zoom.x -= 1;
        map->zoom.y -= 1;
        map->zoom.z -= 1;
    }
    draw_map(map);
    draw_img(map);
    clear_img(map);
    return (0);
}