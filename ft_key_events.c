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

static void	ft_change_max(int keycode, t_mlx *mlx)
{
	mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->str_img = (int *)mlx_get_data_addr(mlx->img->img,
		&(mlx->img->bpp), &(mlx->img->s_l), &(mlx->img->endian));
	if (keycode == 69)
		mlx->fract->max += 50;
	else if (keycode == 78 && mlx->fract->max >= 100)
		mlx->fract->max -= 50;
	ft_draw(mlx, mlx->img, mlx->fract);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
}

static void	ft_move(int keycode, t_mlx *mlx)
{
	mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->str_img = (int *)mlx_get_data_addr(mlx->img->img,
		&(mlx->img->bpp), &(mlx->img->s_l), &(mlx->img->endian));
	if (keycode == 123)
		mlx->fract->x1 -= 10 / (mlx->fract->zoom_x * 2);
	else if (keycode == 124)
		mlx->fract->x1 += 10 / (mlx->fract->zoom_x * 2);
	else if (keycode == 125)
		mlx->fract->y1 += 10 / (mlx->fract->zoom_y * 2);
	else if (keycode == 126)
		mlx->fract->y1 -= 10 / (mlx->fract->zoom_y * 2);
	ft_draw(mlx, mlx->img, mlx->fract);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
}

static void	ft_zoom(int keycode, t_mlx *mlx)
{
	mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->str_img = (int *)mlx_get_data_addr(mlx->img->img,
		&(mlx->img->bpp), &(mlx->img->s_l), &(mlx->img->endian));
	if (keycode == 13)
	{
		mlx->fract->x1 += 100 / mlx->fract->zoom_x;
		mlx->fract->y1 += 100 / mlx->fract->zoom_y;
		mlx->fract->zoom_x += mlx->fract->zoom_x * 1.05 / 2;
		mlx->fract->zoom_y += mlx->fract->zoom_y * 1.05 / 2;
	}
	else if (keycode == 1)
	{
		mlx->fract->x1 -= 100 / mlx->fract->zoom_x;
		mlx->fract->y1 -= 100 / mlx->fract->zoom_y;
		mlx->fract->zoom_x -= mlx->fract->zoom_x * 0.5 / 2;
		mlx->fract->zoom_y -= mlx->fract->zoom_y * 0.5 / 2;
	}
	ft_draw(mlx, mlx->img, mlx->fract);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
}

static void	ft_change_fract(int keycode, t_mlx *mlx)
{
	if (keycode == 48)
	{
		if (mlx->num > 0 && mlx->num < 7)
			mlx->num = mlx->num + 1;
		else
			mlx->num = 1;
		mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
		ft_exec_frac(mlx, mlx->img, mlx->fract);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	}
	else if (keycode == 51)
	{
		mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
		ft_exec_frac(mlx, mlx->img, mlx->fract);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	}
}

int			ft_key_events(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 13 || keycode == 1)
		ft_zoom(keycode, mlx);
	else if (keycode == 8)
		ft_change_color(mlx);
	else if (keycode == 48 || keycode == 51)
		ft_change_fract(keycode, mlx);
	else if (keycode == 123 || keycode == 124 ||
		keycode == 125 || keycode == 126)
		ft_move(keycode, mlx);
	else if (keycode == 69 || keycode == 78)
		ft_change_max(keycode, mlx);
	else if (keycode == 49)
	{
		if (mlx->stop == 1)
			mlx->stop = 0;
		else
			mlx->stop = 1;
	}
	ft_expose_hook(mlx);
	return (0);
}
