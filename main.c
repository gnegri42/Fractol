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

int		ft_key_events(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

void	ft_fill_pixel(t_img img, int x, int y, color)
{
	int i;

	i = x + y * WIN_WIDTH;
	img.str_img[i] = color;
}

int		main()
{
	t_mlx	mlx;
	t_img	img;

	mlx.img = &img;
	mlx.mlx = mlx_init();
	img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.str_img = (int *)mlx_get_data_addr(img.img, &(img.bpp), &(img.s_l), &(img.endian));
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	ft_draw_mandelbrot(img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, ft_key_events, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
