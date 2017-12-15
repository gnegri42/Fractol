/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:23:27 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/15 10:23:29 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_events(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 13)
	{
		mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
		mlx->img->str_img = (int *)mlx_get_data_addr(mlx->img->img, &(mlx->img->bpp), &(mlx->img->s_l), &(mlx->img->endian));
		mlx->fract->zoom_x += 10;
		mlx->fract->zoom_y += 10;
		ft_draw(*mlx, *mlx->img, mlx->fract);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	}
	return (0);
}
