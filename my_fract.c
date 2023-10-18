/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:20:29 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/17 15:15:43 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void	iter_calc(t_fractol *data)
{
	double	c;
	double	a;
	double	b;

	data->iter = 0;
	while (data->iter < data->max_iter)
	{
		data->oldre = data->newre;
		data->oldim = data->newim;
		a = data->oldre;
		b = data->oldim;
		c = (((a * a - b * b) * (a * a - b * b) + 4 * a * a * b * b) * 3);
		data->newre = a - 0.0371 * (2 * a * a * a * b * b + a * b * b * b * b + \
			a * a * a * a * a - a * a + b * b) / c;
		data->newim = b - 0.0371 * (a * a * a * a * b + 2 * a * a * b * b * b + \
			b * b * b * b * b + 2 * a * b) / c;
		data->iter++;
		if ((data->newre * data->newre) + (data->newim * data->newim) > 4)
			break ;
	}
}

void	my_fract(t_fractol *data)
{
	data->newre = (data->x * data->x_scale) - data->x_center;
	data->newim = (data->y * data->y_scale) - data->y_center;
	iter_calc(data);
}
