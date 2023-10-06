/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:40:30 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/06 14:00:55 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	iter_calc(t_fractol *data)
{
	data->iter = 0;
	while (data->iter < data->max_iter)
	{
		data->oldre = data->newre;
		data->oldim = data->newim;
		data->newre = (data->oldre * data->oldre) - \
					(data->oldim * data->oldim) + data->c_r;
		data->newim = 2 * data->oldre * data->oldim + data->c_i;
		data->iter++;
		if ((data->newre * data->newre) + (data->newim * data->newim) > 4)
			break ;
	}
}

void	mandelbrot(t_fractol *data)
{
	data->newre = 0;
	data->newim = 0;
	data->c_r = (data->x * data->x_scale) - data->x_center;
	data->c_i = (data->y * data->y_scale) - data->y_center;
	iter_calc(data);
}
