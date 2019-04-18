/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:19:12 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/17 17:14:18 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3		rotate(t_vec3 px, double angle_x, double angle_y, double angle_z)
{
    px = (t_vec3){ px.x,
                   px.y * cos(angle_x) + px.z * sin(angle_x),
                   -px.y * sin(angle_x) + px.z * cos(angle_x) };

    px = (t_vec3){ px.x * cos(angle_y) + px.z * sin(angle_y),
				   px.y,
				   -px.x * sin(angle_y) + px.z * cos(angle_y) };

    px = (t_vec3){  px.x * cos(angle_z) - px.y * sin(angle_z),
                    px.x * sin(angle_z) + px.y * cos(angle_z),
                    px.z };
	return (px);
}