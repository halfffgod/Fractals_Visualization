/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:40:38 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/16 11:09:18 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_default(int ac, char **av, t_fractol *data)
{
	if (ac == 2)
	{
		data->julia_var_re = 0;
		data->julia_var_im = 0.8;
	}
	else if (ac == 4)
	{
			data->julia_var_re = atoi_d(av[2]);
			data->julia_var_im = atoi_d(av[3]) * (-1);
	}
}

static void	iter_calc(t_fractol *data)
{
	data->iter = 0;
	while (data->iter < data->max_iter)
	{
		data->oldre = data->newre;
		data->oldim = data->newim;
		data->newre = (data->oldre * data->oldre) - \
						(data->oldim * data->oldim) + data->julia_var_re;
		data->newim = 2 * data->oldre * data->oldim + data->julia_var_im;
		data->iter++;
		if ((data->newre * data->newre) + (data->newim * data->newim) > 4)
			break ;
	}
}

void	julia(t_fractol *data)
{
	data->newre = (data->x * data->x_scale) - data->x_center;
	data->newim = (data->y * data->y_scale) - data->y_center;
	iter_calc(data);
}
