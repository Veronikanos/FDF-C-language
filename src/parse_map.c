/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <vtlostiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:48:16 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/06 20:24:22 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		atoi_letter_check(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

static int		ft_atoi_base_color(const char *str, size_t *i)
{
	int 		res;

	res = 0;
	if (str[(*i)++] == ',' && str[(*i)++] == '0' && str[(*i)++] == 'x')
	{
		while (str[*i] != 32 && str[*i] != '\n' && str[*i] != '\0')
		{
			if (is_hex(str[*i]))
				res = res * 16 + atoi_letter_check(str[*i]);
			else
				errors_msg(3);
			(*i)++;
		}
	}
	else
		res = COLOR;
	return (res);
}

static int		ft_atoi_i(const char *str, size_t *i)
{
	size_t		num;
	char	minus;

	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\r'
	   || str[*i] == '\n' || str[*i] == '\v' || str[*i] == '\f')
		(*i)++;
	num = 0;
	minus = 1;
	if (str[*i] == '-')
		minus = -1;
	while (str[*i] == '+' || str[*i] == '-')
		(*i)++;
	while (str[*i] && (str[*i] >= '0') && (str[*i] <= '9'))
	{
		num = (num * 10) + ((int)str[*i] - '0');
		(*i)++;
	}
	if ((num > 9223372036854775807 && minus == 1))
		return (-1);
	if (num > 9223372036854775807 && minus == -1)
		return (0);
	return ((int)(num * minus));
}

int		parsing(t_map *map, t_lines *lines_head)
{
	size_t	y;
	size_t	x;
	size_t	i;

	if (!(map->coord = (t_coord **)ft_memalloc(map->height * sizeof(t_coord *))))
		errors_msg(4);
	y = -1;
	while (lines_head && ++y < map->height)
	{
		if (!(map->coord[y] = (t_coord *)ft_memalloc(map->width * sizeof(t_coord))))
			errors_msg(4);
		x = -1;
		i = 0;
		while (++x < map->width)
		{
			map->coord[y][x].pos.y = y;
			map->coord[y][x].pos.x = x;
			map->coord[y][x].pos.z = ft_atoi_i(lines_head->str, &i);
			map->coord[y][x].z_orig = map->coord[y][x].pos.z;
			map->coord[y][x].color = ft_atoi_base_color(lines_head->str, &i);
		}
		lines_head = lines_head->next;
	}
	return (0);
}
