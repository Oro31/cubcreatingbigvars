/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:56:50 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 10:36:52 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bpp;
	int	ll;
	int	e;
}		t_data;

typedef	struct	s_spr
{
	char	**path;
	t_data	*data;
}			t_spr;

typedef	struct	s_rsl
{
	int		w;
	int		h;
}			t_rsl;

typedef	struct	s_rgb
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	int		color;
}			t_rgb;

typedef	struct	s_cam
{
	int		posx;
	int		posy;
	int		dir;
}			t_cam;

typedef	struct	s_map
{
	char		**box;
	t_cam	cam;
}		t_map;

typedef	struct	s_all
{
	t_data	img;
	t_spr	sprites;
	t_map	map;
	t_rsl	rsl;
	t_rgb	*ground;
	t_rgb	*sky;
}		t_all;

void	ft_parse_line(int checkline, t_all *vars, char *line);

char	*ft_parse_path(char *line, int iswall);
int		ft_parse_tex(char *line, char **tpath);

void	ft_parse_rsl(char *line, t_rsl *rsl);

void	ft_rgb_fill(t_rgb *rgb, char *line);

int	ft_rgbtocolor(t_rgb *rgb);
t_rgb	*ft_colortorgb(int color);

void	ft_mymlx_pixelput(t_data *data, int skycolor, int groundcolor);

int		ft_istex_line(char *line);
int		ft_isrgb_line(char *line);
int		ft_ismap_line(char *line);
int		ft_check_line(char *line);

int		ft_ismap_member(char c);
int		ft_len_mpline(char *line);
char	*ft_linemap_realloc(char **map, int i);
char	*ft_linemap_fill(char *line, int maxlen);
char	**ft_parse_map(char *line, char **map);

int		ft_lenmax_mpline(char **map);
int		ft_is_space_diagwalled_tool(char **map, int i, int j, int len);
int		ft_is_space_diagwalled(char **map, int i, int j, int len);
int		ft_is_space_walled(char**map, int i, int j, int len);
int		ft_ismap_walled(char **map);

int		ft_isdigit(int c);

#endif
