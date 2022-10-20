/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:29:55 by abelhadi          #+#    #+#             */
/*   Updated: 2022/10/20 17:12:57 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define PI 3.141592653589793

// DIMENSIONS AND VALUES
# define HEIGHT 800
# define WIDTH 1024
# define CENTER 400
# define WIDTH_3D 640
# define HEIGHT_3D 400
# define SPEED 3
# define WALLS_SIDE 64
# define DIST_TO_PLANE 255
// # define FOV 1.0472
// # define HALF_FOV

// COLORS
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define GREY 0x00808080
# define YELLOW 0x00FFFF00
# define RED 0x00FF0000
# define GREEN 0x00008000
# define DARK_BLUE 0x00063970
# define ROYAL_BLUE 0x00154c79
# define BLUE 0x001e81b0
# define BABY_BLUE 0x0076b5c5

// DIRECTIONS
# define RIGHT 1
# define LEFT 2
# define UP 3
# define DOWN 4
# define VERT 1
# define HOR 2
# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4

// KEY AND MOUSE CODES
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

// STRUCTS
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bpix;
	int		line;
	int		end;
}				t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpix;
	int		line;
	int		endian;
}				t_img;

typedef struct s_data
{
	char	*filename;
	char	**file;
	char	**map;
	char	**texture_color;
	int		map_size;
	int		map_len;
	int		error_no;
	int		found;
	int		fd;
	int		mid_line;
	int		i;
	int		j;
}	t_data;

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct s_cub
{
	char	**cubmap;
	char	**txtur;
	t_img	textures[4];   // PARSED TEXTURE FILES 
	int		rgb[2][3];
	double	poz[2];
	int		map_height;
	int		map_len;
	double	angle;
	double	ray;
	double	ray_3d;
	int		i;
	int		j;
	int		closest_wall;
	t_mlx	*mini;
	t_mlx	*map3d;
	t_point	*player;
	t_point	intersection;
	bool	w_key;
	bool	a_key;
	bool	s_key;
	bool	d_key;
	bool	left_arrow;
	bool	right_arrow;
}	t_cub;

typedef	struct s_directions
{
	int	up;
	int	down;
	int	left;
	int	right;
}				t_directions;


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

//***************************** P A R S I N G **************************************

//PARSING FUNCTIONS
t_cub		*parsing(char *description_file);
t_cub		*extract_data(int descrip_fd, t_data *data);
t_data		*init_data(t_data *data, char *filename);

//EXTRACT_DATA FUNCTIONS
void		get_map(t_data *d);
t_cub		*clean_map(t_data *d);
void		get_texture_color(t_data *data);
void		init_cub(t_data *d, t_cub *cub);
int			parse_file(int descrip_fd, t_data *data);
void		last_validation(t_data *data, t_cub *cub);

//GET_TEXTURES
int			check_xpm(char *str);
void		parse_txtur(t_cub *c);
void		clean_texture(t_cub *cub);
int			find_mapstart(char **file);
void		copy_textures_tab(t_data *data, t_cub *cub);
int			get_texture(t_data *data, char *line, char *identifier, int index);

//GET_MAP
int			find_maplen(t_data *d);
int			good_line(int end, int index, int start, char *line);

//CLEAN_MAP && LAST_VALIDATION
int			is_open(char c, int mode);
int			longest_str(char	**map);
int			is_persona(char c, int mode);
void		map_error(char **map, int i, int j, int MODE);
size_t		cub_strlcpy(char *dst, const char *src, size_t dstsize);

//COLOR FUNCTIONS
int			isnum_check(char *t);
long		ft_atoi_custom(const char *str);
void		get_color(t_data *d, t_cub *cub);
void		verify_color(t_data *data, t_cub *cub, int index, int type);

//KEY_MANAGER FUNCTIONS
int			key_manager(int key, t_cub *cub);

//UTILS
int			bad_charac(char *c);
char		*cub_free(char *str);
int			is_map_or_error(char c);
void		error(char	*error_msg);
int			open_file(char	*filename);
int			ft_strcmp(const char *s1, const char *s2);

//FREE
void			free_data(t_data *d);
char			**free_tab(char **tab);

// ************************* 2D ENGINE FUNCTIONS **************************

// void		draw_2d(t_cub *cub);

// ************************* 3D ENGINE FUNCTIONS **************************

// ************************* R A Y - C A S T I N G **************************

// MLX
void			init_window(t_cub **data, int length, int height); // mini map window : to be deleted later
void			put_pixel_to_image(t_cub *data, double x, double y, int color);

// 3D RENDER UTILS
void			lay_background(t_cub *data);
void			init_3d_map(t_cub *data);
void			get_directions_3d(t_cub *data, t_directions *dir); // to be merged with get_directions later
void			put_pixel_to_image_3d(t_cub *data, double x, double y, int color);

// RAY CASTING UTILS
double			abs_val(double number);
void			get_map_param(t_cub *cub);
void			init_character(t_cub *data);
void			modulo_two_pi(double *angle);
double			get_y_coordinate(double y_pixel);
double			get_x_coordinate(double x_pixel);
int				is_wall(t_cub *data, t_point *point);
void			check_limits(t_cub *data, t_point *point);
double			get_distance(t_point *player, t_point *wall);
double			get_right_angle(t_cub *data, t_directions *dir, int grid);

// RAY CASTING (for both 3d render & mini-map)
t_point			*check_ver_intersections(t_cub *data, t_point *player, t_directions *dir);
t_point			*check_hor_intersections(t_cub *data, t_point *player, t_directions *dir);

// 3D RENDER
void			draw_3d(t_cub *data);
void			draw_walls(t_cub *data);
int				render_3d(t_cub *data);

// MINI MAP
void			draw2d(t_cub *cub);
void			draw_map(t_cub *cub);
void			paint_fov(t_cub *data);
int				render_2d(t_cub *data);
void			show_character(t_cub *data);
void			draw_character(t_cub *data);
t_directions	*get_directions(t_cub *data); // to be merged with get_directions_3d later
void			dda(t_cub *data, t_point a, t_point b, int color);

// HOOKS
int				rotation_and_moves(t_cub *data);
int				key_press(int keycode, t_cub *data);
int				key_release(int keycode, t_cub *data);
int				check_collisions(t_cub *data, double x, double y);

//TEXTURES & COLORS
int				get_wall_color(t_cub *data);
int				get_floor_or_ceiling_color(t_cub *data, int floor_or_ceiling);
int				wall_orientation(t_cub *data);
unsigned int	texturing(t_cub *data, double projected_height, double y_wall);

#endif