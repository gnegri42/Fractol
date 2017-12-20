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

void	ft_draw(t_mlx *mlx, t_img *img, t_fract *fract)
{
	if (mlx->num == 1)
		ft_draw_mandelbrot(mlx, img, fract);
	else if (mlx->num == 2)
		ft_draw_julia(mlx, img, fract);
	else if (mlx->num == 3)
		ft_draw_bship(mlx, img, fract);
	else if (mlx->num == 4)
		ft_draw_sierpinski(mlx, img, fract);
}
