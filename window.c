/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:34:10 by axcallet          #+#    #+#             */
/*   Updated: 2022/12/13 09:50:05 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_start_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			data->win_x, data->win_y, "Ft_fractol");
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	data->img_addr = mlx_get_data_addr(data->img_ptr,
			&data->bpp, &data->s_line, &data->endian);
}

void	ft_close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	ft_mlx_close(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (0);
}
