/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <vtlostiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:23:34 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/06 20:21:01 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_hex(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

static size_t		ft_is_color(char const *str, size_t *i)
{
	size_t len;

	(*i)++;
	if (str[*i] == '0' && str[*i + 1] == 'x')
	{
		(*i) += 2;
		len = 0;
		while (str[*i] != 32 && str[*i] != '\n' && str[*i] != '\0')
		{
			if (!(is_hex(str[*i])))
				errors_msg(1);
			len++;
			(*i)++;
		}
	}
	else
		errors_msg(1);
	if (len < 1 || len > 8)
		errors_msg(1);
	return (*i);
}

static int		is_valid_row(char const *buf)
{
	size_t i;

	i = 0;
	if (!buf)
		errors_msg(5);
	while (buf[i] != '\0')
	{
		if ((buf[i] == '-') && (ft_isdigit(buf[i + 1])) && (buf[i + 1] != '\0'))
			i++;
		else if (buf[i] == 32 || ft_isdigit(buf[i]))
			i++;
		else if (buf[i] == ',' && ft_isdigit(buf[i - 1]))
		{
			i = ft_is_color(buf, &i);
			i++;
		}
		else
			errors_msg(1);
	}
	return (1);
}

void		is_file_valid(t_map *map, t_lines **lines_head)
{
	char	*buf;
	int		i;

	i = 0;
	while (get_next_line(map->fd, &buf) == 1 && ++i)
	{
		if (is_valid_row(buf))
		{
			++map->heigth;
			if (map->width == 0)
			{
				if ((map->width = ft_count_words(buf, 32)) == 0)
					errors_msg(1);
				ft_add_to_end(lines_head, buf, map->width);
			}
			else
			{
				if (map->width == ft_count_words(buf, 32))
					ft_add_to_end(lines_head, buf, map->width);
				else
				{
					ft_del_all(lines_head);
					errors_msg(1);
				}
			}
			ft_memdel((void *) &buf);
		}
	}
	i == 0 ? errors_msg(1) : 0;
}