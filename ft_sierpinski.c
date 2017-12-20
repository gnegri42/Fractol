/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sierpinski.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:57:30 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/18 15:57:39 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_sierpinski(t_fract *fract)
{	
	fract->x1 = -5;
	fract->x2 = 5;
	fract->y1 = -5;
	fract->y2 = 5;
	fract->zoom_x = WIN_WIDTH / (fract->x2 - fract->x1);
	fract->zoom_y = WIN_HEIGHT / (fract->y2 - fract->y1);
	fract->max = 100;
	fract->x = 0;
	fract->y = 0;
}

void	ft_draw_sierpinski(t_mlx *mlx, t_img *img, t_fract *fract)
{
	int		i;
	double	x;
	double	y;
	
	x = mlx->fract->x;
	while (x < WIN_WIDTH)
	{
		y = fract->y;
		while (y < WIN_HEIGHT)
		{
			i = -1;
			fract->z_r = x + fract->zoom_x - fract->x1;
			fract->z_i = y + fract->zoom_y - fract->y1;
			fract->z_r /= 3;
			fract->z_i /= 3;
			/*
			while ((int)fract->z_r % 3 == 1 && (int)fract->z_i % 3 == 1 && ++i < fract->max)
			{
				fract->z_r /= 3;
				fract->z_i /= 3;
			}
			if (x == 1 && y == 1)
				ft_fill_pixel(*img, x, y, BLACK);
			else
			*/
				ft_fill_pixel(*img, x, y, WHITE);
			y++;
		}
		x++;
	}

	/*
	x = fract->x;
	while (x < WIN_WIDTH)
	{
		y = fract->y;
		while (y < WIN_HEIGHT)
		{
			i = -1;
			fract->z_r = x + fract->zoom_x - fract->x1;
			fract->z_i = y + fract->zoom_y - fract->y1;
			while ((int)fract->z_r % 3 == 1 && (int)fract->z_i % 3 == 1 && ++i < fract->max)
			{
				fract->z_r /= 3;
				fract->z_i /= 3;
			}
			if (i != fract->max)
				ft_fill_pixel(*img, x, y, BLACK);
			else
				ft_fill_pixel(*img, x, y, ft_get_color(i, mlx));
			y++;
		}
		x++;
	}
	
	x = fract->x;
	while (x < WIN_WIDTH)
	{
		y = fract->y;
		while (y < WIN_HEIGHT)
		{
			fract->c_r = x / fract->zoom_x + fract->x1;
			fract->c_i = y / fract->zoom_y + fract->y1;
			i = 0;
			while (fract->z_r * fract->z_r + fract->z_i * fract->z_i < 4
				&& i < fract->max)
			{
				
				tmp = fract->z_r;
				fract->z_r = fract->z_r * fract->z_r - fract->z_i *
				fract->z_i + fract->c_r;
				fract->z_i = tmp * fract->z_i + tmp * fract->z_i + fract->c_i;
				i++;
			}
			if (i == fract->max)
				ft_fill_pixel(*img, x, y, BLACK);
			else
				ft_fill_pixel(*img, x, y, YELLOW);
			y++;
		}
		x++;
	}
	if (mlx)
	{}
	*/
}
