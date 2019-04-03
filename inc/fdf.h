/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <vtlostiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:28:00 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/03 18:23:16 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "get_next_line.h"
# include "libft.h"

# define WIDTH		1920
# define HEIGHT		1080
# define NAME		"FDF BY VTLOSTIU"

enum			keys
{
	ESC = 53,
};

typedef	struct 		s_coordinates
{
	double	x;
	double 	y;
	double  z;
	double 	z_orig;
	int 	color;
}					t_coord;

typedef struct		s_map
{
	size_t		width;
	size_t		heigth;
	t_coord		**coord;
	int			fd;
}						t_map;

typedef struct 			s_lines
{
	char			*str;
	struct s_lines	*next;
	size_t			words;
}						t_lines;

void    is_file_valid(t_map *map, t_lines **lines_head);
void	errors_msg(int err);
void	ft_add_to_end(t_lines **head, char *str, size_t words);
void	ft_del_all(t_lines **head);
int		parsing(t_map *map, t_lines *lines_head);
int		is_hex(char c);
// int		ft_atoi_i(const char *str, size_t *i);

#endif
