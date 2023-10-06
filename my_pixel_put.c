/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:01:25 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/06 14:02:51 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + \
		(y * data->img.line_length + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}
