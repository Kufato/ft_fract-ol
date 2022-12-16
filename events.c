/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:24:34 by axcallet          #+#    #+#             */
/*   Updated: 2022/12/16 15:24:16 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_events(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, ft_mlx_close, data);
	mlx_hook(data->mlx_win, 2, 1L, ft_key_hook, data);
	mlx_mouse_hook(data->mlx_win, mouse_hook, data);
}

int	ft_key_hook(int key_code, t_data *data)
{
	if (key_code == 65307)
		ft_mlx_close(data);
	if (key_code == 65362) // flêche du haut
	{
		data->crd_x += 0.05;
		put_fractal(data);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_ptr, 0, 0);
	}
	// else if (key_code == 65361) // flêche de gauche

	// else if (key_code == 65364) // flêche du bas

	// else if (key_code == 65363) // flêche de droite
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)mouse_code;
	(void)data;
 	// if (mouse_code == 4)
	// 	data->zoom *= 0.05;
	// else if (mouse_code == 5)
	// 	data->zoom /= 0.05;
	// put_fractal(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_ptr, 0, 0);
	return (0);
}
