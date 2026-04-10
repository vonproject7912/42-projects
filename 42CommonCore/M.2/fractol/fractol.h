/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:33:28 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:53:08 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define SKY_BLUE 0x87CEEB
# define RED 0xFF0000

typedef struct s_image
{
	void	*img;
	char	*address;
	int		bpp;
	int		size_line;
	int		endian;
}			t_image;

typedef struct s_file
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	double	escaped_value;
	int		fractal_iteration;
	double	x_shift;
	double	y_shift;
	double	zoom;
	t_image	image;
	double	julia_x;
	double	julia_y;
}			t_file;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}			t_complex;

/////////////////////////////////////////////////////////////////////////
/*        UTILS      */
void		error_mess(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
static int	get_sign(char *str, int *i); // potential issue ?
double		atodbl(char *str);

/*        MATH UTILS       */
double		my_scale(int pixel, int max_pixel, double new_min, double new_max);
t_complex	adding_c(t_complex z, t_complex c);
t_complex	square_complex(t_complex z1);

/*        RENDER UTILS      */
int			get_color(double i, int max_iter);
void		my_pixel_put(int x, int y, t_image image, int color);
int			get_smooth_color(int i, t_complex z, t_file *fractal);

/*          RENDER          */
void		handle_pixel_mandelbrot(int x, int y, t_file *fractal);
void		handle_pixel_julia(int x, int y, t_file *fractal);
void		fractal_render(t_file *fractal);

/*       EVENTS        */
void		events_handling(t_file *fractal);
int			key_handling(int keysym, t_file *fractal);
int			exit_handling(t_file *fractal);
int			mouse_handling(int button, int x, int y, t_file *fractal);

/*    FRACTOL MOUHAHA */
void		failed_malloc(void);
void		data_init(t_file *fractal);
void		fractal_init(t_file *fractal);
/////////////////////////////////////////////////////////////////////////

#endif