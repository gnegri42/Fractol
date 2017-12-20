/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:00:45 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/18 12:00:47 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_zoom(int button, int x, int y, t_mlx *mlx)
{
	mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->str_img = (int *)mlx_get_data_addr(mlx->img->img,
		&(mlx->img->bpp), &(mlx->img->s_l), &(mlx->img->endian));
	if (x >= WIN_WIDTH || y >= WIN_HEIGHT || x <= 0 || y <= 0)
		return (0);
	mlx->fract->tmp_x1 = mlx->fract->x1 + x * (mlx->fract->x2 - mlx->fract->x1) / WIN_WIDTH;
	mlx->fract->tmp_y1 = mlx->fract->y1 + y * (mlx->fract->y2 - mlx->fract->y1) / WIN_HEIGHT;
	mlx->fract->tmp_x2 = mlx->fract->x1;
	mlx->fract->tmp_y2 = mlx->fract->y1;
	if (button == 4 && mlx->fract->nb_zoom > 0)
	{
		mlx->fract->zoom_x -= mlx->fract->zoom_x * 0.2;
		mlx->fract->zoom_y -= mlx->fract->zoom_y * 0.2;
		mlx->fract->nb_zoom--;
	}
	if (button == 5)
	{
		mlx->fract->zoom_x += mlx->fract->zoom_x * 1.025;
		mlx->fract->zoom_y += mlx->fract->zoom_y * 1.025;
		mlx->fract->x1 = mlx->fract->tmp_x1 - (mlx->fract->x2 - mlx->fract->x1) / 4;
		mlx->fract->y1 = mlx->fract->tmp_y1 - (mlx->fract->y2 - mlx->fract->y1) / 4;
		mlx->fract->x2 = mlx->fract->tmp_x1 + (mlx->fract->x2 - mlx->fract->tmp_x2) / 4;
		mlx->fract->y2 = mlx->fract->tmp_y1 + (mlx->fract->y2 - mlx->fract->tmp_y2) / 4;
		mlx->fract->nb_zoom++;
	}
	ft_draw(mlx, mlx->img, mlx->fract);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	return (0);
}

int		ft_move_julia(int x, int y, t_mlx *mlx)
{
	if (x <= WIN_WIDTH && y <= WIN_HEIGHT && x >= 0 && y >= 0 && mlx->num == 2 && mlx->stop == 0)
	{
		mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
		mlx->img->str_img = (int *)mlx_get_data_addr(mlx->img->img,
		&(mlx->img->bpp), &(mlx->img->s_l), &(mlx->img->endian));
		mlx->fract->c_r = (double)x / (double)WIN_WIDTH * 4 - 2;
		mlx->fract->c_i = (double)y / (double)WIN_HEIGHT * 4 - 2;
		ft_draw(mlx, mlx->img, mlx->fract);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
		mlx_destroy_image(mlx->mlx, mlx->img->img);;
	}
	return (0);
}
