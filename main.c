/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:57:51 by axcallet          #+#    #+#             */
/*   Updated: 2022/12/16 15:26:39 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (ft_error(argc, argv) == 1)
		return (1);
	data->win_x = ft_atoi(argv[2]);
	data->win_y = ft_atoi(argv[3]);
	data->zoom = 1.0;
	data->z.r = 0.0;
	data->z.i = 0.0;
	data->c.r = 0.0;
	data->c.i = 0.0;
	data->model = chose_model(argv);
	if (data->model == 2)
	{
		data->c.r = ft_atof(argv[4]);
		data->c.i = ft_atof(argv[5]);
	}
	ft_start_window(data);
	put_fractal(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_ptr, 0, 0);
	ft_events(data);
	mlx_loop(data->mlx_ptr);
	ft_close_window(data);
	free(data);
}
