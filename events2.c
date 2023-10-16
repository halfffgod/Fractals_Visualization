/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:27:50 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/16 11:27:59 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_press(int key, int x, int y, t_fractol *data)
{
	if (key == 4)
	{
		data->x_scale *= 0.5;
		data->y_scale *= 0.5;
		data->max_iter += 20;
		data->x_center = data->x_center - (x * data->x_scale);
		data->y_center = data->y_center - (y * data->y_scale);
	}
	else if (key == 5)
	{
		data->x_center = data->x_center + (x * data->x_scale);
		data->y_center = data->y_center + (y * data->y_scale);
		data->x_scale /= 0.5;
		data->y_scale /= 0.5;
		data->max_iter -= 20;
	}
	else if (key == 1)
		data->value2 += 1;
	return (0);
}

int	mouse_move(int x, int y, t_fractol *data)
{
	if (data->value2 % 2)
	{
		if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
		{
			data->julia_var_re = (data->x_scale * x) - data->x_center;
			data->julia_var_im = (data->x_scale * y) - data->y_center;
		}
		else
			return (0);
	}
	else if (!data->value2 % 2)
	{
		data->julia_var_re = data->julia_var_re;
		data->julia_var_im = data->julia_var_im;
	}
	return (0);
}
