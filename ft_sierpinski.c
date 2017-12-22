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
	fract->zoom_x = 0.00005;
	fract->zoom_y = 0.00005;
	fract->max = 50;
	fract->x = 0;
	fract->y = 0;
}

int		ft_sierpinski(int x, int y, t_fract *fract)
{
	int		i;

	i = 0;
	x = x / fract->zoom_x + fract->x1;
	y = y / fract->zoom_y + fract->y1;
	while ((x > 0 || y > 0) && i < fract->max)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (1);
}

void	ft_draw_sierpinski(t_mlx *mlx, t_img *img, t_fract *fract)
{
	double	x;
	double	y;

	mlx->fract->x = 0;
	x = (int)mlx->fract->x;
	while (x < WIN_WIDTH)
	{
		y = (int)fract->y;
		while (y < WIN_HEIGHT)
		{
			if (ft_sierpinski(x, y, fract) == 1)
				ft_fill_pixel(*img, x, y, WHITE);
			else
				ft_fill_pixel(*img, x, y, BLACK);
			y++;
		}
		x++;
	}
}
