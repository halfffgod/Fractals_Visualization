/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:40:08 by nbadalia          #+#    #+#             */
/*   Updated: 2023/10/16 11:10:34 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# define WIDTH	700 
# define HEIGHT	700
# define COLOR	0x000000

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractol {
	void	*mlx;
	void	*mlx_wind;
	int		x;
	int		y;
	double	julia_var_re;
	double	julia_var_im;
	int		iter;
	int		max_iter;
	int		color;
	int		in_min;
	int		in_max;
	int		out_max;
	int		out_min;
	double	x_scale;
	double	y_scale;
	double	x_center;
	double	y_center;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	int		value2;
	int		value;
	double	c_r;
	double	c_i;
	int		color_code;
	t_data	img;
}	t_fractol;

// functions from libft
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

// initialization functions
void	fractal_init(t_fractol *data);
void	get_colors(t_fractol *data);
void	my_pixel_put(t_fractol *data, int x, int y, int color);
void	get_color(t_fractol *data);

//fractals
void	mandelbrot(t_fractol *data);
void	julia_default(int ac, char **av, t_fractol *data);
void	julia(t_fractol *data);
void	my_fract(t_fractol *data);

//drawing
void	lets_draw(t_fractol *data, void (*f)(t_fractol *));
int		closing(t_fractol *data);
int		key_press(int keycode, t_fractol *data);
int		mouse_press(int key, int x, int y, t_fractol *data);
int		mouse_move(int x, int y, t_fractol *data);
int		handle_no_event(t_fractol *data);

void	errors(void);
int		is_numeric(const char *str);
double	atoi_d(const char *str);

#endif
