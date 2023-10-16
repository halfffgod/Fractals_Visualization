/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:47:59 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/16 11:08:31 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->mlx_wind = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract_ol");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, \
			&data->img.line_length, &data->img.endian);
	data->x_scale = (4.0 / WIDTH);
	data->y_scale = (4.0 / HEIGHT);
	data->x_center = 2.0;
	data->y_center = 2.0;
	data->max_iter = 80;
	data->color = 0xEE33FF; //fuck colors
	data->color_code = 0;
}

void	get_color(t_fractol *data)
{
	data->color_code++;
	if (data->color_code == 0)
		data->color = 0x9C789D;
	else if (data->color_code == 1)
		data->color = 0xA88A30;
	else if (data->color_code == 2)
		data->color = 0x677E24;
	else if (data->color_code == 3)
		data->color = 0xA17DBE;
	else if (data->color_code == 4)
		data->color = 0x24677E;
	else if (data->color_code == 5)
		data->color = 0xFFFFD9;
	else if (data->color_code == 6)
		data->color = 0xFFFCA7;
	else if (data->color_code == 7)
		data->color = 0xf1f1e1;
	else if (data->color_code == 8)
		data->color = 0xF4E7FA;
	else if (data->color_code == 9)
		data->color_code = 0;
}
