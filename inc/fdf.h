/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <vtlostiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:28:00 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/04/04 20:59:46 by vtlostiu         ###   ########.fr       */
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

# define WIDTH			1920
# define HEIGHT			1080
# define HALF_WIDTH		960
# define HALF_HEIGHT	540
# define NAME		"FDF BY VTLOSTIU"

enum			keys
{
	ESC = 53, LEFT_ARROW = 123,
	RIGHT_ARROW = 124, UP_ARROW = 126,
	DOWN_ARROW = 125, MOUSE_UP = 4,
	MOUSE_DOWN = 5,

};

typedef	struct 		s_coordinates
{
	double	x;
	double 	y;
	double  z;
	double 	z_orig;
	int 	color;
}					t_coord;

typedef	struct 		s_vector
{
	int		x;
	int		y;
}					t_vec;

typedef struct		s_map
{
	size_t		width;
	size_t		heigth;
	size_t 		zoom;
	t_vec 		move;
	t_coord		**coord;
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
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
void	draw_map(t_map *map);
// int		ft_atoi_i(const char *str, size_t *i);

#endif
