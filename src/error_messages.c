/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtlostiu <vtlostiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:55:38 by vtlostiu          #+#    #+#             */
/*   Updated: 2019/03/14 17:56:35 by vtlostiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	errors_msg(int err)
{
	if (err == 2)
		ft_putendl("Incorrect number of arguments.\n");
	else if (err == 1)
		ft_putendl("Incorrect file or impossible to write file.\n");
	else if (err == 3)
		ft_putendl("Incorrect color.\n");
	else if (err == 4)
		ft_putendl("Impossible to allocate memory.\n");
	else if (err == 5)
		ft_putendl("There are no string to write from file.\n");
//	ft_putendl("just err\n");
system("leaks -q fdf");
	exit(0);
}