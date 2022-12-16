/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:04:41 by axcallet          #+#    #+#             */
/*   Updated: 2022/12/16 16:06:18 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# include <stdio.h> //Remove before push !!!
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

typedef struct s_cpx
{
	double	r;
	double	i;
}				t_cpx;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		s_line;
	int		endian;
	int		win_x;
	int		win_y;
	int		model;
	double	crd_x;
	double	crd_y;
	double	zoom;
	t_cpx	z;
	t_cpx	c;
}				t_data;

int		chose_model(char **argv);
int		ft_mlx_close(t_data *data);
int		main(int argc, char **argv);
int		ft_error(int argc, char **argv);
int		algo_fractal(t_data *data, int max_iter);
int		ft_key_hook(int key_code, t_data *data);
int		mouse_hook(int mouse_code, int x, int y, t_data *data);

void	ft_events(t_data *data);
void	apply_model(t_data *data);
void	put_fractal(t_data *data);
void	ft_start_window(t_data *data);
void	ft_close_window(t_data *data);
void	put_pixel(t_data *data, int i, int max_iter);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

t_cpx	crd_convert(t_data *data);

#endif
