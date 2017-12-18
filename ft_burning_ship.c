/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:11:49 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/14 10:11:50 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	ft_init_bship(t_fract *fract)
{
	fract->x = 0;
	fract->y = 0;
	fract->x1 = -1.813659;
	fract->x2 = 1;
	fract->y1 = -0.086517;
	fract->y2 = 1.2;
	fract->zoom_x = WIN_WIDTH * 10;
	fract->zoom_y = WIN_WIDTH * 10;
	fract->max = 100;
}

void	ft_draw_bship(t_mlx *mlx, t_img *img, t_fract *fract)
{
	int		i;
	int		x;
	int		y;
	double	tmp;

	x = fract->x;
	while (x < WIN_WIDTH)
	{
		y = fract->y;
		while (y < WIN_HEIGHT)
		{
			fract->c_r = x / fract->zoom_x + fract->x1;
			fract->c_i = y / fract->zoom_y + fract->y1;
			i = 0;
			fract->z_r = 0;
			fract->z_i = 0;
			while (fract->z_r * fract->z_r + fract->z_i * fract->z_i < 4
				&& i < fract->max)
			{
				
				tmp = fract->z_r;
				fract->z_r = fract->z_r * fract->z_r - fract->z_i *
				fract->z_i + fract->c_r;
				fract->z_r = fract->z_r < 0 ? -fract->z_r : fract->z_r;
				fract->z_i = 2 * tmp * fract->z_i + fract->c_i;
				fract->z_i = fract->z_i < 0 ? -1 * fract->z_i : fract->z_i;
				i++;
			}
			if (i == fract->max)
				ft_fill_pixel(*img, x, y, ORANGE);
			else
				ft_fill_pixel(*img, x, y, ft_get_color(i, mlx));
			y++;
		}
		x++;
	}
}