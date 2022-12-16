/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:06:31 by axcallet          #+#    #+#             */
/*   Updated: 2022/12/13 17:06:37 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_error(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("Error, invalid number of arguments", 1);
		return (1);
	}
	if ((ft_strncmp("mandelbrot", argv[1], 11) != 0)
		&& (ft_strncmp("julia", argv[1], 5) != 0))
	{
		ft_putstr_fd("Error, the chosen model is not good", 1);
		return (1);
	}
	if ((ft_atoi(argv[2]) > 1920) || (ft_atoi(argv[3]) > 1080))
	{
		ft_putstr_fd("Error, the chosen size is too big", 1);
		return (1);
	}
	if ((ft_strncmp("julia", argv[1], 5) == 0)
		&& ((ft_atof(argv[4]) > 2.0 || ft_atof(argv[4]) < -2.0)
			|| (ft_atof(argv[5]) > 2.0 || ft_atof(argv[5]) < -2.0)))
	{
		ft_putstr_fd("Error, the parameters are invalid", 1);
		return (1);
	}
	return (0);
}
