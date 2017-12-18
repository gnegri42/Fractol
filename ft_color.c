/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:34:39 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/18 10:34:40 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_change_color(t_mlx *mlx)
{
	mlx->color_value += 1;
	mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->str_img = (int *)mlx_get_data_addr(mlx->img->img,
		&(mlx->img->bpp), &(mlx->img->s_l), &(mlx->img->endian));
	ft_draw(mlx, mlx->img, mlx->fract);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
}

unsigned int	ft_get_color(int i, t_mlx *mlx)
{
	unsigned int	c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (i * 4) * mlx->color_value;
	g = (255 - (i * 3)) * mlx->color_value;
	b = (255 - (i * 12)) * mlx->color_value;
	c = (r << 16) + (g << 8) + b;
	return (c);
}
