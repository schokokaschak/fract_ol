/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:02:57 by akashets          #+#    #+#             */
/*   Updated: 2023/02/23 14:03:01 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_run(t_data *mlx, int flag)
{
	if (mlx->fractol == 1)
	{
		if (flag)
			mandelbrot(mlx);
		else
			start_mandelbrot();
	}
	if (mlx->fractol == 2)
	{
		if (flag)
			julia(mlx);
		else
			start_julia();
	}
	if (mlx->fractol == 3)
	{
		if (flag)
			burning(mlx);
		else
			start_burning();
	}
}

void	ft_usage(int flag)
{
	if (flag)
		ft_putendl_fd(".:: Usage: ./fractol <name> ::.", 1);
	ft_putendl_fd(".:: List of available fractals ::.", 1);
	ft_putendl_fd(":::          Mandelbrot        :::", 1);
	ft_putendl_fd(":::            Julia           :::", 1);
	ft_putendl_fd(":::         Burningship       :::\n", 1);
}

void	ft_how_to_use(t_data *m)
{
	mlx_string_put(m->mlx, m->win, 15, 30, 0xFFFFFF, "     Keys to use:");
	mlx_string_put(m->mlx, m->win, 15, 45, 0xFFFFFF, " Scroll up to zoom in");
	mlx_string_put(m->mlx, m->win, 15, 60, 0xFFFFFF, "Scroll down to zoom out");
	mlx_string_put(m->mlx, m->win, 15, 75, 0xFFFFFF, "   C: change colors");
	mlx_string_put(m->mlx, m->win, 15, 90, 0xFFFFFF, " Use arrows to navigate");
	mlx_string_put(m->mlx, m->win, 15, 105, 0xFFFFFF, "WASD to change Julia");
}

int	main(int argc, char *argv[])
{
	t_data	mlx;

	mlx.fractol = 0;
	if (argc >= 2)
	{
		ft_usage(0);
		if (!ft_strcmp(argv[1], "Mandelbrot"))
			mlx.fractol = 1;
		else if (!ft_strcmp(argv[1], "Julia"))
			mlx.fractol = 2;
		else if (!ft_strcmp(argv[1], "Burningship"))
			mlx.fractol = 3;
		ft_run(&mlx, 0);
	}
	else
	{
		ft_putendl_fd(".::: The parameters is invalid! :::.", 1);
		ft_usage(1);
	}
}
