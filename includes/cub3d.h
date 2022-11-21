/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:29:55 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/21 18:31:03 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <pthread.h>
# include <time.h>
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
# define MINI_RATIO 10
# define DIST_TO_OPEN_DOORS 20
# define ANGLE_INCREMENT 0.00163624617 // = (PI / 3) / WIDTH_3D 
# define CHRONO_START 30
# define DIST_TO_TRANSFORM_PEACH 50

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
# define DARK_PURPLE 0x003d253b
# define PURPLE 0x006e4a48

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
# define SCROLL_DOWN 4
# define SCROLL_UP 5
# define SPACE_BAR 49
# define RED_CROSS 17

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
	bool	paintings_mode;
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
	void	*txtr_mlx_ptr;
	void	*txtr_mlx_ptr_bonus;
	t_img	textures[6];
	t_img	painting_textures[8];
	t_img	right_texture;
	int		rgb[2][3];
	double	poz[2];
	int		map_height;
	int		map_len;
	int		mini_height;
	int		mini_width;
	double	angle;
	double	ray;
	double	ray_3d;
	int		i;
	int		j;
	int		closest_wall;
	double	dist_to_closest_wall;
	t_mlx	*map3d;
	t_point	*player;
	t_point	intersection;
	t_point	mini_playr;
	bool	w_key;
	bool	a_key;
	bool	s_key;
	bool	d_key;
	bool	left_arrow;
	bool	right_arrow;
	bool	fake_door_mode;
	bool	paintings_mode;
	int		time_left;
}	t_cub;

typedef struct s_directions
{
	int	up;
	int	down;
	int	left;
	int	right;
}				t_directions;

enum	e_type
{
	NO = 0,
	EA,
	SO,
	WE,
	DOOR,
	END,
	RANDOM1,
	RANDOM2,
	RANDOM3,
	RANDOM4,
	RANDOM5,
	RANDOM6,
	RANDOM7,
	RANDOM8,
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

//******************** P A R S I N G **************************

//PARSING FUNCTIONS
t_cub			*parsing(char *description_file);
t_cub			*extract_data(int descrip_fd, t_data *data);
t_data			*init_data(t_data *data, char *filename);

//EXTRACT_DATA FUNCTIONS
void			get_map(t_data *d);
t_cub			*clean_map(t_data *d);
void			get_texture_color(t_data *data);
void			init_cub(t_data *d, t_cub *cub);
int				parse_file(int descrip_fd, t_data *data);
void			last_validation(t_data *data, t_cub *cub);

//GET_TEXTURES
int				check_xpm(char *str);
void			parse_txtur(t_cub *c);
void			clean_texture(t_cub *cub);
int				find_mapstart(char **file);
void			copy_textures_tab(t_data *data, t_cub *cub);
int				get_texture(t_data *data, char *line,
					char *identifier, int index);

//GET_MAP
int				find_maplen(t_data *d);
int				good_line(int end, int index, int start, char *line);

//CLEAN_MAP && LAST_VALIDATION
int				is_open(char c, int mode);
int				longest_str(char	**map);
int				is_persona(char c, int mode);
void			map_error(char **map, int i, int j, int MODE);
size_t			cub_strlcpy(char *dst, const char *src, size_t dstsize);
int				persona_position(t_cub *cub);

//COLOR FUNCTIONS
int				isnum_check(char *t);
long			ft_atoi_custom(const char *str);
void			get_color(t_data *d, t_cub *cub);
void			verify_color(t_data *data, t_cub *cub, int index, int type);

//KEY_MANAGER FUNCTIONS
int				key_manager(int key, t_cub *cub);
int				red_cross(int mousecode, t_cub *data);

//UTILS
int				bad_charac(char *c);
char			*cub_free(char *str);
int				is_map_or_error(char c);
void			error(char	*error_msg);
int				open_file(char	*filename);
int				ft_strcmp(const char *s1, const char *s2);

//FREE
void			free_data(t_data *d);
void			free_tab(char **tab);
void			end_cub(t_cub *data);

// ************************* 2D ENGINE FUNCTIONS **************************

// void		draw_2d(t_cub *cub);

// ************************* 3D ENGINE FUNCTIONS **************************

// ************************* R A Y - C A S T I N G **************************

// MLX
void			put_pixel_to_image(t_cub *data, double x, double y, int color);

// 3D RENDER UTILS
void			lay_background(t_cub *data);
void			init_3d_map(t_cub *data);
void			get_directions_3d(t_cub *data, t_directions *dir);
void			put_pixel_to_image_3d(t_cub *data, double x,
					double y, int color);

// RAY CASTING UTILS
double			abs_val(double number);
void			get_map_param(t_cub *cub);
void			find_character_in_map(t_cub *data);
void			init_character_pos(t_cub *data, int x, int y);
void			modulo_two_pi(double *angle);
double			get_y_coordinate(double y_pixel);
double			get_x_coordinate(double x_pixel);
int				is_wall(t_cub *data, t_point *point);
void			check_limits(t_cub *data, t_point *point);
double			get_distance(t_point *player, t_point *wall);
double			get_right_angle(t_cub *data, t_directions *dir, int grid);

// RAY CASTING (for both 3d render & mini-map)
t_point			*check_ver_intersections(t_cub *data,
					t_point *player, t_directions *dir);
t_point			*check_hor_intersections(t_cub *data,
					t_point *player, t_directions *dir);
double			closest_wall(t_cub *data, t_point *hor_inter,
					t_point *ver_inter);
t_point			*get_first_hor_intersection(t_cub *data,
					t_point *player, t_directions *dir);
t_point			*get_first_ver_intersection(t_cub *data,
					t_point *player, t_directions *dir);
double			find_wall(t_cub *data);

// 3D RENDER
void			draw_3d(t_cub *data);
void			draw_walls(t_cub *data);
int				render_3d(t_cub *data);

// HOOKS & MOVEMENTS
int				rotation_and_moves(t_cub *data);
int				key_press(int keycode, t_cub *data);
int				key_release(int keycode, t_cub *data);
int				check_collisions(t_cub *data, double x, double y);
void			forward_moves(t_cub *data);
void			lateral_moves(t_cub *data);
void			rotation(t_cub *data);

//TEXTURES & COLORS
int				get_wall_color(t_cub *data);
int				get_floor_or_ceiling_color(t_cub *data, int floor_or_ceiling);
int				wall_orientation(t_cub *data);
unsigned int	texturing(t_cub *data, double projected_height, double y_wall);

// ************************* B O N U S E S **************************

// MINI MAP
void			draw_3d_bonus(t_cub *data);
int				render_3d_bonus(t_cub *data);
void			draw2d(t_cub *cub);
void			draw_map(t_cub *cub);
void			paint_fov(t_cub *data);
int				render_2d(t_cub *data);
void			show_character(t_cub *data);
void			draw_character(t_cub *data);
t_directions	*get_directions(t_cub *data);
void			dda(t_cub *data, t_point a, t_point b, int color);
void			find_character_in_map_bonus(t_cub *data);
int				bonus_moves(t_cub *data);
int				key_press_bonus(int keycode, t_cub *data);
int				key_release_bonus(int keycode, t_cub *data);

// PARSING
t_cub			*parsing_bonus(char *description_file);
void			get_map_bonus(t_data *d);
int				good_line_bonus(int end, int index, int start, char *line);
int				bad_charac_bonus(char *c);
int				bad_charac_inside_bonus(char c);
int				is_map_or_error_bonus(char c);
void			get_texture_color_bonus(t_data *d);
int				find_mapstart_bonus(char **file);
void			copy_textures_tab_bonus(t_data *d, t_cub *c);
void			get_color_bonus(t_data *d, t_cub *cub);
void			parse_painting_txtur(t_cub *c);
void			init_paintings_mode(t_data *data, char *map_name);

// TEXTURES
unsigned int	texturing_bonus(t_cub *data,
					double projected_height, double y_wall);
void			textures_rng(t_cub *data);
t_img			get_random_painting(t_cub *data, int index);
int				check_for_door_or_special_txtr(t_cub *data);
void			turn_peach_into_bowser(t_cub *data);

// DOORS
void			look_for_door_close(t_cub *data);

// FAKE DOOR MODE
void			enable_chrono_mode(t_cub *data);
void			display_chrono(t_cub *data);

// HOOKS
int				mouse_press_bonus(int mousecode, int x, int y, t_cub *data);
int				mouse_release_bonus(int mousecode, int x, int y, t_cub *data);

#endif