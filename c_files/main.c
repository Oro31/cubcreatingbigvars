/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 08:42:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{
	int	fd;
	char	*line;
	t_all	vars;
	void	*mlx;
	void	*win;
	int	i;
	int	j;

	printf("start \n");
	vars.rsl.w = 0;
	vars.rsl.h = 0;
	if (!(vars.map.box = malloc(sizeof(char*))))
		return (0);
	vars.map.box[0] = NULL;
	if (!(vars.sprites.path = malloc(sizeof(char*) * 6)))
		return (0);
	vars.sprites.path[5] = NULL;
	if (!(fd = open("map.cub", O_RDONLY)))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		printf("gnl running /\n");
		ft_parse_line(ft_check_line(line), &vars, line);
		/*if (ft_check_line(line) == 2)
		{
			j = ft_parse_tex(line, vars.sprites.path);
			if (j == 1)
				printf("parse tex : SUCCES \n");
		}
		else if (ft_check_line(line) == 1)
		{
			ft_parse_rsl(line, &vars.rsl);
			printf("w = %d, h = %d \n", vars.rsl.w, vars.rsl.h);
		}
		else if (ft_check_line(line) == 3)
		{
			if (line[0] == 'F')
				ft_rgb_fill(&vars.ground, line);
			else
				ft_rgb_fill(&vars.sky, line);
		}
		else if (ft_check_line(line) == 4)
		{
			printf("before parse map \n");
			vars.map.box = ft_parse_map(line, vars.map.box);
		}*/
		/*if (ft_parse(line) != 1)
			return (0);*/
		/*if (!(map = ft_firstdim_mapalloc(line, map, fstdmsz)))
			return (0);
		fstdmsz++;*/
	}
	vars.ground->color = ft_rgbtocolor(vars.ground);
	vars.sky->color = ft_rgbtocolor(vars.sky);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "SandG");
	vars.img.img = mlx_new_image(mlx, 640, 480);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bpp, &vars.img.ll, &vars.img.e);
	ft_mymlx_pixelput(&vars.img, vars.sky->color, vars.ground->color);
	mlx_put_image_to_window(mlx, win, vars.img.img, 0, 0);
	mlx_loop(mlx);
	printf("is map walled ? %d \n", ft_ismap_walled(vars.map.box));
	i = 0;
	while (vars.sprites.path[i])
	{
		printf("texpath[%d] = %s \n", i, vars.sprites.path[i]);
		free(vars.sprites.path[i]);
		i++;
	}
	free(vars.sprites.path);
	i = 0;
	while(vars.map.box[i])
	{
		printf("map[%d] = %s \n", i , vars.map.box[i]);
		free(vars.map.box[i]);
		i++;
	}
	free(vars.map.box);
	close(fd);
	return (0);
}
