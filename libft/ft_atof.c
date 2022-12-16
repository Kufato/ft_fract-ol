/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:05:26 by axcallet          #+#    #+#             */
/*   Updated: 2022/12/08 15:43:15 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	ft_atof_decimal(char *nptr, int i)
{
	double	res;
	double	div;

	res = 0.0;
	div = 0.1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (nptr[i] - 48) * div + res;
		div = div / 10;
		i++;
	}
	return (res);
}

double	ft_atof(char *nptr)
{
	int		i;
	double	n;
	double	res_int;
	double	res_dec;

	i = 0;
	n = 1.0;
	res_int = 0.0;
	res_dec = 0.0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n = n * -1.0;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i] != '.')
	{
		res_int = res_int * 10 + (nptr[i] - 48);
		i++;
	}
	res_dec = ft_atof_decimal(nptr, i + 1);
	return ((res_int + res_dec) * n);
}
