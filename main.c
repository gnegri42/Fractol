/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:53:09 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/13 09:53:11 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_events(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 13)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
		ft_draw_mandelbrot(*mlx->img);
	}
	return (0);
}

void	ft_fill_pixel(t_img img, int x, int y, int color)
{
	int i;

	i = x + y * WIN_WIDTH;
	img.str_img[i] = color;
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;

	mlx.img = &img;
	if (ft_check_errors(argc, argv) != 1)
		return (0);
	mlx.mlx = mlx_init();
	img.str_img = (int *)malloc(sizeof(int) * (WIN_WIDTH * WIN_HEIGHT));
	img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.str_img = (int *)mlx_get_data_addr(img.img, &(img.bpp), &(img.s_l), &(img.endian));
	if (ft_strcmp(argv[1], "1") == 0)
		ft_draw_mandelbrot(img);
	else if (ft_strcmp(argv[1], "2") == 0)
		ft_draw_julia(img);
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, ft_key_events, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
