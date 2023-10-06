/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:40:38 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/06 13:51:49 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//declare atoi_d() func here
int is_numeric(const char *str) {
    if (!str || *str == '\0')
        return 0;

    int i = 0;
    int len = 0;
    int has_decimal = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;

    while (str[i] != '\0') {
        if (str[i] == '.') {
            if (has_decimal)
                return 0;  // More than one decimal point
            has_decimal = 1;
        } else if (str[i] < '0' || str[i] > '9') {
            return 0;  // Invalid character
        }

        i++;
        len++;
    }

    // Ensure at least one digit is present
    return len > 0;
}

double atoi_d(const char *str) 
{
    double result = 0.0;
    int sign = 1;

    while (*str == ' ' || (*str >= '\t' && *str <= '\r')) str++;
    if (*str == '-' || *str == '+') sign = (*str++ == '-') ? -1 : 1;

    int decimal_found = 0;
    while (*str && ((*str >= '0' && *str <= '9') || (*str == '.' && !decimal_found))) {
        if (*str == '.') {
            decimal_found = 1;
            str++;
            continue;
        }

        if (!decimal_found) result = result * 10.0 + (*str - '0');
        else result = result + ((*str - '0') / 10.0);

        str++;
    }

    return sign * result;
}


void	julia_default(int ac, char **av, t_fractol *data)
{

	if (ac == 2)
	{
		data->julia_var_re = -0.7269;
		data->julia_var_im = 0.1889;
	}
	else if(ac == 4)
	{
			data->julia_var_re = atoi_d(av[2]);
			data->julia_var_im = atoi_d(av[3]);
		
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
