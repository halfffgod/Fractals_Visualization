/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:54:36 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/16 11:12:23 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	checking(int ac, char **av, t_fractol *data)
{
	if (ac == 4 && (is_numeric(av[2]) == 0 || is_numeric(av[3]) == 0))
		errors();
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0
		&& ft_strlen(av[1]) == 10)
	{
		data->value = 0;
		lets_draw(data, &mandelbrot);
		return (1);
	}
	else if ((ft_strncmp(av[1], "julia", 5) == 0
			&& ft_strlen(av[1]) == 5))
	{
		data->value = 1;
		julia_default(ac, av, data);
		lets_draw(data, &julia);
		return (1);
	}
	else
		errors();
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	*data;

	data = (t_fractol *)malloc(sizeof(t_fractol));
	if (!data)
		return (-1);
	fractal_init(data);
	if (ac == 2 || ac == 4)
	{
		if (checking(ac, av, data) == 1)
		{
			mlx_key_hook(data->mlx_wind, &key_press, data);
			mlx_hook(data->mlx_wind, 53, 0, &closing, data);
			mlx_hook(data->mlx_wind, 17, 0, &closing, data);
			mlx_hook(data->mlx_wind, 4, 0, &mouse_press, data);
			mlx_hook(data->mlx_wind, 6, 0, &mouse_move, data);
			mlx_loop_hook(data->mlx, &handle_no_event, data);
			mlx_loop(data->mlx);
		}
	}
	else
		errors();
}
