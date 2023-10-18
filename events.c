/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:24:38 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/16 11:06:20 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	closing(t_fractol *data)
{
	(void)data;
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_wind);
	free(data);
	exit(0);
}

void	reset_fract(t_fractol *data)
{
	data->x_scale = (4.0 / WIDTH);
	data->y_scale = (4.0 / HEIGHT);
	data->x_center = 2.0;
	data->y_center = 2.0;
	data->max_iter = 50;
	if (data->value == 0)
		lets_draw(data, &mandelbrot);
	else if (data->value == 1)
		lets_draw(data, &julia);
	else if (data->value == 2)
		lets_draw(data, &my_fract);
}

int	handle_no_event(t_fractol *data)
{
	if (data->value == 0)
		lets_draw(data, &mandelbrot);
	else if (data->value == 1)
		lets_draw(data, &julia);
	else if (data->value == 2)
		lets_draw(data, &my_fract);
	return (0);
}

int	key_press(int keycode, t_fractol *data)
{
	(void)data;
	if (keycode == 53)
		exit(0);
	else if (keycode == 126)
		data->y_center += 30 * data->x_scale;
	else if (keycode == 125)
		data->y_center -= 30 * data->x_scale;
	else if (keycode == 124)
		data->x_center -= 30 * data->x_scale;
	else if (keycode == 123)
		data->x_center += 30 * data->x_scale;
	else if (keycode == 69)
		data->max_iter += 50;
	else if (keycode == 78)
		data->max_iter -= 50;
	else if (keycode == 15)
		reset_fract(data);
	else if (keycode == 35)
		get_color(data);
	return (0);
}
