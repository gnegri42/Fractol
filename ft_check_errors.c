/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:17:58 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/14 15:17:59 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_check_errors(int argc, char **argv)
{
	if (argc != 2 || (ft_strcmp(argv[1], "1") != 0 &&
		ft_strcmp(argv[1], "2") != 0 && ft_strcmp(argv[1], "3") != 0 &&
		ft_strcmp(argv[1], "4") != 0 && ft_strcmp(argv[1], "5") != 0 &&
		ft_strcmp(argv[1], "6") != 0 && ft_strcmp(argv[1], "7") != 0))
	{
		ft_putstr("usage: ./fractol number\n");
		ft_putstr("1 = Mandlebrot\n");
		ft_putstr("2 = Julia\n");
		ft_putstr("3 = Burning ship\n");
		ft_putstr("4 = Sierpinski Carpet\n");
		ft_putstr("5 = Calc\n");
		ft_putstr("6 = Thunder\n");
		ft_putstr("7 = Coton\n");
		return (0);
	}
	return (1);
}
