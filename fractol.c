/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:00:37 by axcallet          #+#    #+#             */
/*   Updated: 2022/12/16 16:13:23 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	put_fractal(t_data *data)
{
	int		i;
	int		max_iter;

	data->crd_x = 0;
	data->crd_y = 0;
	i = 0;
	max_iter = 50;
	while (data->crd_y < data->win_y)
	{
		data->crd_x = 0;
		while (data->crd_x < data->win_x)
		{
			apply_model(data);
			i = 0;
			i = algo_fractal(data, max_iter);
			put_pixel(data, i, max_iter);
			data->crd_x++;
		}
		data->crd_y++;
	}
}

void	apply_model(t_data *data)
{
	if (data->model == 1)
	{
		data->c = crd_convert(data);
		data->z.r = 0.0;
		data->z.i = 0.0;
	}
	else if (data->model == 2)
	{
		data->z = crd_convert(data);
	}
}

int	algo_fractal(t_data *data, int max_iter)
{
	t_cpx	tmp;
	int		i;

	tmp.r = 0;
	tmp.i = 0;
	i = 0;
	while ((data->z.r * data->z.r + data->z.i * data->z.i) < 4.0 && i < max_iter)
	{
		tmp.r = data->z.r;
		tmp.i = data->z.i;
		data->z.r = tmp.r * tmp.r - tmp.i * tmp.i + data->c.r;
		data->z.i = 2.0 * tmp.r * tmp.i + data->c.i;
		i++;
	}
	return (i);
}
