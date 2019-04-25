/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:23:34 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/25 17:42:17 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				is_hex(char c)
{
	if (ft_isdigit(c)
	|| (c >= 'a' && c <= 'f')
	|| (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

static int		ft_is_color(char const *str, size_t *i)
{
	size_t len;

	++(*i);
	if (str[(*i)++] == '0' && str[(*i)++] == 'x')
	{
		len = 0;
		while (str[*i] && str[*i] != ' ')
		{
			if (is_hex(str[*i]))
				len++;
			else
				errors_msg(1);
			(*i)++;
		}
	}
	else
		errors_msg(1);
	if (len < 1 || len > 8)
		errors_msg(1);
	return (1);
}

static int		is_valid_row(char const *buf)
{
	size_t i;

	if (!buf)
		errors_msg(5);
	i = 0;
	while (buf[i])
	{
		if (!(((buf[i] == '-' || buf[i] == '+') && ft_isdigit(buf[i + 1]))
		|| buf[i] == ' '
		|| ft_isdigit(buf[i])
		|| (buf[i] == ',' && ft_isdigit(buf[i - 1]) && ft_is_color(buf, &i))))
			errors_msg(1);
		if (buf[i])
			++i;
	}
	return (1);
}

void			is_file_valid(t_map *map, t_lines **lines_head)
{
	char	*buf;

	while (get_next_line(map->fd, &buf) == 1
	&& ++map->height && is_valid_row(buf))
	{
		if (map->width == 0)
		{
			if ((map->width = ft_count_words(buf, 32)) == 0)
				errors_msg(1);
			ft_add_to_end(lines_head, buf);
		}
		else
		{
			if (map->width == ft_count_words(buf, 32))
				ft_add_to_end(lines_head, buf);
			else
			{
				ft_del_all(lines_head);
				errors_msg(1);
			}
		}
		ft_memdel((void *)&buf);
	}
	map->height == 0 ? errors_msg(1) : 0;
}
