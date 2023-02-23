/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:02:07 by akashets          #+#    #+#             */
/*   Updated: 2023/02/23 14:02:16 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_exit(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i] && s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	move(int keycode, t_data *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->xmax - mlx->xmin);
	dy = (mlx->ymax - mlx->ymin);
	if (keycode == 53)
		ft_exit(mlx);
	if (keycode == 123 || keycode == 124)
	{
		if (keycode == 123)
			dx *= -1;
		mlx->xmin += dx / 7.5;
		mlx->xmax += dx / 7.5;
	}
	if (keycode == 126 || keycode == 125)
	{
		if (keycode == 125)
			dy *= -1;
		mlx->ymin += dy / 7.5;
		mlx->ymax += dy / 7.5;
	}
}

int	keys(int keycode, t_data *mlx)
{
	if (keycode == 53 || keycode == 123 || keycode == 124 \
		|| keycode == 126 || keycode == 125)
		move(keycode, mlx);
	if (keycode == 8)
	{
		if (mlx->color == 3)
			mlx->color = 0;
		else
			mlx->color += 1;
	}
	if (keycode == 1)
		mlx->juliay += 0.2;
	if (keycode == 13)
		mlx->juliay -= 0.2;
	if (keycode == 0)
		mlx->juliax -= 0.2;
	if (keycode == 2)
		mlx->juliax += 0.2;
	ft_run(mlx, 1);
	return (0);
}

int	zoom(int keycode, int x, int y, t_data *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->xmax - mlx->xmin) / SIZEX;
	dy = (mlx->ymax - mlx->ymin) / SIZEY;
	if (keycode == 5)
	{
		mlx->xmin = (mlx->xmin + ((dx * x) * 0.2));
		mlx->xmax = (mlx->xmax - ((dx * (SIZEX - x)) * 0.2));
		mlx->ymax = (mlx->ymax - ((dy * y) * 0.2));
		mlx->ymin = (mlx->ymin + ((dy * (SIZEY - y)) * 0.2));
		mlx->iteration += 1;
	}
	if (keycode == 4)
	{
		mlx->xmin = (mlx->xmin - ((dx * x) * 0.2));
		mlx->xmax = (mlx->xmax + ((dx * (SIZEX - x)) * 0.2));
		mlx->ymax = (mlx->ymax + ((dy * y) * 0.2));
		mlx->ymin = (mlx->ymin - ((dy * (SIZEY - y)) * 0.2));
		mlx->iteration -= 1;
	}
	ft_run(mlx, 1);
	return (0);
}
