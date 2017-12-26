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

static void	ft_call_hooks(t_mlx mlx)
{
	mlx_hook(mlx.win, 2, 1L << 0, ft_key_events, &mlx);
	mlx_hook(mlx.win, 4, 1L << 12, ft_mouse_zoom, &mlx);
	mlx_hook(mlx.win, 6, 1L << 6, ft_move_julia, &mlx);
}

void		ft_exec_frac(t_mlx *mlx, t_img *img, t_fract *fract)
{
	if (mlx->num == 1)
	{
		ft_init_mandel(fract);
		ft_draw(mlx, img, fract);
	}
	else if (mlx->num == 2)
	{
		ft_init_julia(fract);
		ft_draw(mlx, img, fract);
	}
	else if (mlx->num == 3)
	{
		ft_init_bship(fract);
		ft_draw(mlx, img, fract);
	}
	else if (mlx->num == 4)
	{
		ft_init_sierpinski(fract);
		ft_draw(mlx, img, fract);
	}
	else if (mlx->num == 5)
	{
		ft_init_thunder(fract);
		ft_draw(mlx, img, fract);
	}
}

void		ft_fill_pixel(t_img img, int x, int y, int color)
{
	int i;

	i = x + y * WIN_WIDTH;
	img.str_img[i] = color;
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;
	t_fract *fract;

	if (ft_check_errors(argc, argv) != 1)
		return (0);
	mlx.mlx = mlx_init();
	mlx.img = &img;
	if (!(fract = (t_fract *)malloc(sizeof(t_fract))))
		return (0);
	mlx.fract = fract;
	mlx.num = ft_atoi(argv[1]);
	mlx.color_value = 1;
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.str_img = (int *)mlx_get_data_addr(img.img,
		&(img.bpp), &(img.s_l), &(img.endian));
	ft_exec_frac(&mlx, mlx.img, mlx.fract);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_destroy_image(mlx.mlx, img.img);
	ft_call_hooks(mlx);
	mlx_loop(mlx.mlx);
	free(fract);
	return (0);
}
