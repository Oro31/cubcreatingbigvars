/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:50:28 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/08 11:03:50 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mymlx_pixelput(t_data *data, int skycolor, int groundcolor)
{
	char	*dst;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 640)
	{
		y = 0;
		while (y < 480)
		{
			dst = data->addr + (y * data->ll + x * (data->bpp / 8));
			if (y < 480 / 2)
				*(unsigned int*)dst = skycolor;
			else
				*(unsigned int*)dst = groundcolor;
			y++;
		}
		x++;
	}
}
