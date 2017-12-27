/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:31:22 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/15 10:31:23 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_expose_hook(t_mlx *mlx)
{
	int			x;
	int			y;

	x = 30;
	y = 40;
	while (x <= 180)
		mlx_pixel_put(mlx->mlx, mlx->win, x++, y, WHITE);
	while (y <= 120)
		mlx_pixel_put(mlx->mlx, mlx->win, x, y++, WHITE);
	while (x >= 30)
		mlx_pixel_put(mlx->mlx, mlx->win, x--, y, WHITE);
	while (y >= 40)
		mlx_pixel_put(mlx->mlx, mlx->win, x, y--, WHITE);
	mlx_string_put(mlx->mlx, mlx->win, 38, 38, WHITE, "Quit = ESC");
	mlx_string_put(mlx->mlx, mlx->win, 38, 58, WHITE, "Move = ^ v < >");
	mlx_string_put(mlx->mlx, mlx->win, 38, 78, WHITE, "Zoom = w s");
	mlx_string_put(mlx->mlx, mlx->win, 38, 98, WHITE, "Up Down = e d");
}

void	ft_draw(t_mlx *mlx, t_img *img, t_fract *fract)
{
	if (mlx->num == 1)
		ft_draw_mandelbrot(mlx, fract);
	else if (mlx->num == 2)
		ft_draw_julia(mlx, fract);
	else if (mlx->num == 3)
		ft_draw_bship(mlx, fract);
	else if (mlx->num == 4)
		ft_draw_sierpinski(mlx, img, fract);
	else if (mlx->num == 5)
		ft_draw_calc(mlx, fract);
	else if (mlx->num == 6)
		ft_draw_thunder(mlx, fract);
	else if (mlx->num == 7)
		ft_draw_coton(mlx, fract);
}
