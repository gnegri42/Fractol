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

void		ft_init_bship(t_fract *fract)
{
	fract->x = 0;
	fract->y = 0;
	fract->x1 = -2.5;
	fract->x2 = 1;
	fract->y1 = -1;
	fract->y2 = 1;
	fract->nb_zoom = 0;
	fract->zoom_x = WIN_WIDTH / (fract->x2 - fract->x1);
	fract->zoom_y = WIN_HEIGHT / (fract->y2 - fract->y1);
	fract->max = 100;
}

static void	ft_draw_bship2(t_mlx *mlx, t_fract *fract, int x, int y)
{
	int		i;
	double	tmp;

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
		ft_fill_pixel(*mlx->img, x, y, ORANGE);
	else
		ft_fill_pixel(*mlx->img, x, y, ft_get_color(i + 238, mlx));
}

void		ft_draw_bship(t_mlx *mlx, t_fract *fract)
{
	int		x;
	int		y;

	x = fract->x;
	while (x < WIN_WIDTH)
	{
		y = fract->y;
		while (y < WIN_HEIGHT)
		{
			ft_draw_bship2(mlx, fract, x, y);
			y++;
		}
		x++;
	}
}
