/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:46:36 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/13 09:46:37 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

# define WIN_WIDTH	1200
# define WIN_HEIGHT	1200
# define IMG_WIDTH	500
# define IMG_HEIGHT	500

# define BLUE 0x1E90FF
# define WHITE 0xFFFFFF
# define GREEN 0x25FF50
# define ORANGE 0x00FFA500
# define YELLOW 0xFFFF66

typedef struct		s_fract
{
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			zoom_x;
	double			zoom_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
}					t_fract;

typedef struct		s_img
{
	void			*img;
	int				*str_img;
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;
}					t_mlx;

void	ft_fill_pixel(t_img img, int x, int y, int color);
void	ft_draw_mandelbrot(t_img img);
void	ft_draw_julia(t_img img);
int		ft_check_errors(int argc, char **argv);

#endif
