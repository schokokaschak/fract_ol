/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:52:44 by akashets          #+#    #+#             */
/*   Updated: 2023/02/23 12:38:40 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	blue(long double t)
{
	int	r;
	int	g;
	int	b;

	r = 9 * (1 - t) * pow(t, 3) * 255;
	g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
	b = 8.5 * pow((1 - t), 3) * t * 255;
	return (create_trgb(0, r, g, b));
}

static int	red(long double t)
{
	int	r;
	int	g;
	int	b;

	r = 9 * (1 - t) * pow(t, 3) * 255;
	g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
	b = 8.5 * pow((1 - t), 3) * t * 255;
	return (create_trgb(0, b, g, r));
}

static int	green(long double t)
{
	int	r;
	int	g;
	int	b;

	r = 9 * (1 - t) * pow(t, 3) * 255;
	g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
	b = 8.5 * pow((1 - t), 3) * t * 255;
	return (create_trgb(0, r, b, g));
}

int	get_color(long double t, int c)
{
	if (c == 0)
		return (blue(t));
	else if (c == 1)
		return (red(t));
	else if (c == 2)
		return (green(t));
	else
		return (0x008DE3EC * t);
}
