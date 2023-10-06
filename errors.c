/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:31:56 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/06 13:47:26 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errors(void)
{
	ft_putstr_fd("\t ERROR!\n\t enter:", 2);
	ft_putstr_fd("\n\t./fractol mandelbrot     or ", 2);
	ft_putstr_fd("\n\t./fractol julia <value_1> <value_2>", 2);
}
