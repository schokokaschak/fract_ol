/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:03:09 by akashets          #+#    #+#             */
/*   Updated: 2023/02/23 14:03:12 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	julia_set(double x, double y, t_data *mlx)
{
	int		i;
	int		k;
	double	xx;
	double	yy;
	double	temp;

	xx = x;
	yy = y;
	i = 1;
	k = mlx->iteration;
	while (i < k)
	{
		temp = xx;
		xx = (pow(xx, 2) - pow(yy, 2)) + 0.103 + mlx->juliax;
		yy = (2 * temp * yy) + 0.321 + mlx->juliay;
		if (pow(xx, 2) + pow(yy, 2) > 4)
		{
			my_mlx_pixel_put(mlx, mlx->loopx, mlx->loopy, \
					get_color((double)((i + 1 - \
				log(log2(xx * xx + yy * yy))) / 2) / k, mlx->color));
			return (0);
		}
		i++;
	}
	return (0);
}

int	julia(t_data *mlx)
{
	double	x;
	double	y;

	mlx->loopx = 0;
	mlx->loopy = 0;
	mlx->img = mlx_new_image(mlx->mlx, SIZEX, SIZEY);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
			&mlx->line_length, &mlx->endian);
	mlx_clear_window(mlx->mlx, mlx->win);
	while (mlx->loopy < SIZEY)
	{
		while (mlx->loopx < SIZEX)
		{
			x = mlx->xmin + (mlx->loopx * ((mlx->xmax - mlx->xmin) / SIZEX));
			y = mlx->ymax - (mlx->loopy * ((mlx->ymax - mlx->ymin) / SIZEY));
			julia_set(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	ft_how_to_use(mlx);
	return (1);
}

void	start_julia(void)
{
	t_data	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZEX, SIZEY, "Fract'ol - Julia");
	mlx.xmin = -2;
	mlx.xmax = 2;
	mlx.ymin = -2;
	mlx.ymax = 2;
	mlx.color = 0;
	mlx.iteration = 70;
	mlx.fractol = 2;
	julia(&mlx);
	mlx_key_hook(mlx.win, keys, &mlx);
	mlx_hook(mlx.win, 17, 2, ft_exit, &mlx);
	mlx_mouse_hook(mlx.win, zoom, &mlx);
	mlx_loop(mlx.mlx);
}
