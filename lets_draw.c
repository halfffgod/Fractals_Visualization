/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:52:43 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/06 13:53:25 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	lets_draw(t_fractol *data, void(*f)(t_fractol *data))
{
	int	color;

	data->x = 0;
	while (data->x < WIDTH)
	{
		data->y = 0;
		while (data->y < HEIGHT)
		{	
			f(data);
			if (data->iter < data->max_iter)
			{
				color = data->iter * data->color;
				my_pixel_put(data, data->x, data->y, color);
			}
			else
				my_pixel_put(data, data->x, data->y, COLOR);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_wind, data->img.img, 0, 0);
}
