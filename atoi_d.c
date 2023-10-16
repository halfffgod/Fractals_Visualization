/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:41:05 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/16 11:03:51 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_numeric(const char *str)
{
	int	i;
	int	len;
	int	has_dec;

	if (!str || *str == '\0')
		return (0);
	i = 0;
	len = 0;
	has_dec = 0;
	if (!str || *str == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			if (has_dec)
				return (0);
			has_dec = 1;
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
		len++;
	}
	return (len > 0);
}

const char	*skip_spaces(const char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	return (str);
}

const char	*signes(const char *str, int *sign)
{
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (str);
}

const char	*atoi_d1(const char *str, double *result, double *dec_nb)
{
	while (*str)
	{
		if (*str == '.')
		{
			str++;
			break ;
		}
		if (*str >= '0' && *str <= '9')
			*result = *result * 10.0 + (*str - '0');
		else
			break ;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			*result += (*str - '0') * (*dec_nb);
			*dec_nb *= 0.1;
		}
		else
			break ;
		str++;
	}
	return (str);
}

double	atoi_d(const char *str)
{
	double	res;
	int		sign;
	double	dec_nb;

	res = 0.0;
	sign = 1;
	dec_nb = 0.1;
	str = skip_spaces(str);
	str = signes(str, &sign);
	str = atoi_d1(str, &res, &dec_nb);
	return (sign * res);
}
