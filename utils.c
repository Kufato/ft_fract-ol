/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:21:20 by axcallet          #+#    #+#             */
/*   Updated: 2022/12/16 16:07:46 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	chose_model(char **argv)
{
	if (ft_strncmp("mandelbrot", argv[1], 10) == 0)
	{
		return (1);
	}
	else if (ft_strncmp("julia", argv[1], 5) == 0)
	{
		return (2);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->s_line + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel(t_data *data, int i, int max_iter)
{
	if (i == max_iter)
		my_mlx_pixel_put(data, data->crd_x, data->crd_y, 0x000000);
	else
		my_mlx_pixel_put(data, data->crd_x, data->crd_y, 0x111330 + i * 10);
}

t_cpx	crd_convert(t_data *data)
{
	t_cpx	res;

	if (data->win_x > data->win_y)
	{
		res.r = ((double)data->crd_x - (data->win_x - data->win_y) / 2.0);
		res.r = (res.r / data->win_y * 4.0 - 2.0) * data->zoom;
		res.i = ((double)data->crd_y / data->win_y * 4.0 - 2.0) * data->zoom;
	}
	else
	{
		res.r = ((double)data->crd_x / data->win_x * 4.0 - 2.0) * data->zoom;
		res.i = ((double)data->crd_y - (data->win_y - data->win_x) / 2.0);
		res.i = (res.i / data->win_x * 4.0 - 2.0) * data->zoom;
	}
	return (res);
}
