/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:29:55 by abelhadi          #+#    #+#             */
/*   Updated: 2022/08/31 15:46:18 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>

# define PI 3.141592653589793
# define HEIGHT 800
# define WIDTH 1024
# define CENTER 400

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_add;
	int		bpix;
	int		line;
	int		end;
}				t_mlx;

typedef struct s_data
{
	char	*filename;
	char	**file;
	char	**map;
	char	**texture_color;
	int		map_size;
	int		error_no;
	int		found;
	int		fd;
	int		mid_line;
	int		i;
	int		j;
}	t_data;

typedef struct s_cub
{
	char	**cubmap;
	char	**textures;
	int		rgb[2][3];
	double	poz[2];
	int		angle;
	int		i;
	int		j;
	void	*mlx;
	void	*win;
	void	*img;
	char	*add;
	int		bpix;
	int		line;
	int		end;
}	t_cub;

//typedef int	(*t_funcptr)(t_utils *, int, t_origin *, int);
//typedef struct s_btin
//{
//	char		*b_in;
//	char		*b_path;
//	t_funcptr	func_ptr;
//}	t_btin;

enum	e_type
{
	NO = 0,
	EA,
	SO,
	WE,
	OPEN,
	WALL,
	SPACE,
	COUNT,
	CHECK,
};

enum	e_texture
{
	FLOOR = 0,
	CEILING,
};

enum	e_position
{
	X = 0,
	Y,
};

//PARSING FUNCTIONS
t_cub		*parsing(char *description_file);
t_cub		*extract_data(int descrip_fd, t_data *data);

t_data		*init_data(t_data *data, char *filename);

//EXTRACT_DATA FUNCTIONS
int			parse_file(int descrip_fd, t_data *data);
void		get_texture_color(t_data *data);
void		get_map(t_data *d);
t_cub		*clean_map(t_data *d);
void		last_validation(t_data *data, t_cub *cub);
void		init_cub(t_data *d, t_cub *cub);
//GET_TEXTURES
int			get_texture(t_data *data, char *line, char *identifier, int index);
int			find_mapstart(char **file);
void		copy_textures_tab(t_data *data, t_cub *cub);
void		clean_texture(t_cub *cub);
//GET_MAP
int			good_line(int end, int index, int start, char *line);
int			find_maplen(t_data *d);
//CLEAN_MAP && LAST_VALIDATION
int			longest_str(char	**map);
size_t		cub_strlcpy(char *dst, const char *src, size_t dstsize);
void		map_error(char **map, int i, int j, int MODE);
int			is_open(char c, int mode);
int			is_persona(char c, int mode);
//COLOR FUNCTIONS
void		get_color(t_data *d, t_cub *cub);
void		verify_color(t_data *data, t_cub *cub, int index, int type);
int			isnum_check(char *t);
long		ft_atoi_custom(const char *str);

//KEY_MANAGER FUNCTIONS
int			key_manager(int key, t_cub *cub);

//2D_ENGINE FUNCTIONS
void		draw_2d(t_cub *cub);

//3D_ENGINE FUNCTIONS
//UTILS
int			open_file(char	*filename);
char		*cub_free(char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			is_map_or_error(char c);
int			bad_charac(char *c);
void		error(char	*error_msg);

//UTILS 2
void		free_data(t_data *d);
char		**free_tab(char **tab);



#endif