#ifndef CUB3D_H
# define CUB3D_H

# include "mlx_linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>

# define PI_1 3.14159265358979323846
# define PI_2 6.28318530717958647692
# define PI_12 1.57079632679489661923
# define PI_32 4.71238898038468985769
# define ONE_DEG 0.01745329251994329576
# define DEG_PER_TURN 3
# define EPS 0.0001
# define MS 15
# define CUBE_POW 7
# define JUMPS 128  
# define BUF_SIZE 4096
# define MIN_WIN_LENGHT 48
# define MIN_WIN_HEIGHT 27
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_ARROW_KEY 65361
# define RIGHT_ARROW_KEY 65363

typedef struct s_tex
{
	char		*addr_n;
	char		*addr_s;
	char		*addr_w;
	char		*addr_e;
	int			bits_per_pixel_n;
	int			bits_per_pixel_s;
	int			bits_per_pixel_w;
	int			bits_per_pixel_e;
	int			line_length_n;
	int			line_length_s;
	int			line_length_w;
	int			line_length_e;
	int			endian;
	int			width_n;
	int			width_s;
	int			width_w;
	int			width_e;
	int			height_n;
	int			height_s;
	int			height_w;
	int			height_e;
	void		*tex_n;
	void		*tex_s;
	void		*tex_w;
	void		*tex_e;
}				t_tex;

typedef struct s_items
{
	char		*addr_1;
	int			bits_per_pixel_1;
	int			line_length_1;
	int			endian;
	int			width_1;
	int			height_1;
	void		*item_1;
	double		dist;
	int			map_tile;
	int			*tiles;
	int			item_1_size;
	int			lcorner_1x;
	int			lcorner_1y;

}				t_items;

typedef struct s_ident
{
	int			r;
	int			f;
	int			c;
	int			s;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			r_ind;
	int			f_ind;
	int			c_ind;
	int			s_ind;
	int			no_ind;
	int			so_ind;
	int			we_ind;
	int			ea_ind;
}				t_ident;

typedef struct s_parser
{
	int			map_rows_amount;
	int			map_row;
	int			amount_of_lines;
}				t_parser;

typedef struct s_dda
{
	double		ctg;
	double		shift_x;
	double		shift_y;
	int			jumps;
	int			map_x;
	int			map_y;
	int			map_current;
}				t_dda;

typedef struct s_d
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	int			x_current;
	int			y_current;
	int			win_lenght;
	int			win_height;
	int			*level_map;
	int			map_lenght;
	int			map_height;
	int			cube_size;
	double		angle;
	double		curr_ray_angle;
	double		ray_hx;
	double		ray_hy;
	double		ray_vx;
	double		ray_vy;
	int			dx;
	int			dy;
	double		perp_ray_len;
	double		curr_ray_len;
	double		*dists;
	double		curr_ray_x;
	double		curr_ray_y;
	int			col_up_x;
	int			column_up_y;
	int			h_ray_shorter;
	int			save;
	char		*argv_content;
	char		**splitted;
	int			floor_color;
	int			ceil_color;
	int			x_diag;
	int			y_diag;
	t_tex		tex;
	t_ident		ident;
	t_items		items;
	t_parser	parser;
	t_dda		dda;
}				t_d;

void			write_items(t_d *d);
void			sort_items(t_d *d);
void			prep_to_draw_item(t_d *d, int map_tile);
void			draw_item(t_d *d, int color, int i, int j);
void			item_loop(t_d *d);
void			ft_bzero(void *str, size_t n);
int				ft_strlen_int(const char *s);
size_t			ft_strlen(const char *s);
int				free_level_map(t_d *d);
int				global_free(t_d *d, int code);
int				null_from_mlxlib(char **path, void **str);
int				long_if_func_for_sort_items(t_d *d, int j);
void			*ft_calloc(size_t amount, size_t size);
char			*ft_strjoin(char const *str1, char const *str2);
int				sum_ints(int i);
int				if_line_valid(const char *str, const char *sample,
					int k, int i);
int				if_sym_valid(const char *str, char c);
int				write_header_1(t_d *d, int fd);
int				write_header_2(t_d *d, int fd);
int				write_image(t_d *d, int fd);
int				save(t_d *d);
void			ident_init(t_d *d);
void			initialization(t_d *d);
int				check_saveargv(const char *str1, const char *str2);
int				names_checker(char *str1, char *str2, int k);
int				check_args(t_d *d, int argc, char **argv);
void			h_prep_dda(t_d *d);
void			h_map_current(t_d *d);
void			h_jumps(t_d *d);
void			h_dda(t_d *d, int *horizontal_hit);
void			v_prep_dda(t_d *d);
void			v_map_current(t_d *d);
void			v_jumps(t_d *d);
void			v_dda(t_d *d, int *vertical_hit);
double			tex_orientation(t_d *d);
void			calc_delta(t_d *d, int *delta);
void			draw_column(t_d *d, int dx, int dy, double col_up_y_cpy);
void			print_3dview(t_d *d, int i);
unsigned int	count(char *s, char c);
void			init_i(size_t *i, size_t l_s1);
char			**free_rez(char **rez);
char			*word_creation(char *str, unsigned int index, char c);
char			**ft_split(char const *s, char c, int index, int jndex);
size_t			first_trim(char const *s1, char const *set,
					size_t l_s1, size_t l_set);
size_t			last_trim(char const *s1, char const *set,
					size_t l_s1, size_t l_set);
char			*ft_strtrim(char const *s1, char const *set);
char			*clear_buf(char *buf);
char			*free_string_ret(char **str1);
char			*free_strings_ret(char **str1, char **str2);
void			free_string(char **s);
char			*read_argv(int fd, int buf_size, char *tmp, char *buf);
void			write_items(t_d *d);
void			sort_items(t_d *d);
void			prep_to_draw_item(t_d *d, int map_tile);
void			draw_item(t_d *d, int color, int i, int j);
void			item_loop(t_d *d);
int				load_no(t_d *d);
int				load_so(t_d *d);
int				load_we(t_d *d);
int				load_ea(t_d *d);
int				load_item(t_d *d);
void			draw_background(t_d *d);
void			set_pos_and_dir(t_d *d, int i, int side);
void			pos_and_dir(t_d *d);
int				load_images(t_d *d);
int				clean_close(t_d *d);
int				move_player(int keycode, t_d *d);
void			main_dda(t_d *d);
int				main_preparations(t_d *d, int argc, char **argv);
int				reading_from_fd(t_d *d, char **argv);
int				map_check_and_measure(t_d *d);
int				amount_of_ident_newlines(char *str);
int				amount_of_map_newlines(char *str, int map_rows_amount, int i);
int				map_check(t_d *d);
int				check_double_spawn(t_d *d);
int				validate_map(t_d *d, int i, int j);
int				atoi_map(t_d *d, char *src, int j, int i);
int				map_parser(t_d *d);
void			remove_periods(t_d *d);
int				move_dep_on_angle_x(t_d *d, int dir);
int				move_dep_on_angle_y(t_d *d, int dir);
void			rotate_left(t_d *d);
void			rotate_right(t_d *d);
void			move_w_if(t_d *d, int tile_x, int tile_y);
void			move_s_if(t_d *d, int tile_x, int tile_y);
void			move_a_if(t_d *d, int tile_x, int tile_y);
void			move_d_if(t_d *d, int tile_x, int tile_y);
int				check_diag_w(t_d *d, int x, int y);
int				check_diag_a(t_d *d, int x, int y);
int				check_diag_s(t_d *d, int x, int y);
int				check_diag_d(t_d *d, int x, int y);
void			move_w(t_d *d);
void			move_s(t_d *d);
void			move_a(t_d *d);
void			move_d(t_d *d);
int				check_argv_4(t_d *d, int i);
int				check_argv_3(t_d *d);
int				check_argv_2(t_d *d);
int				check_argv_1(t_d *d);
int				parser(t_d *d, char **argv);
void			my_mlx_pixel_put(t_d *d, int x, int y, int color);
int				get_tex_pixel_color(t_d *d, int x, int y);
int				get_item_pixel_color(t_d *d, int x, int y);
int				counter(int number);
int				counter_s(char *str);
long			first_app_index(char *str, char c);
long			last_app_index(char *str, char c);
int				atoi_color(char *str, long int i);
int				parse_color_f_c(char *str);
void			res_assignment(t_d *d, int w, int h);
int				atoi_res(char *str, int i);
int				set_res(t_d *d, char *str, int i);
int				set_ident(t_d *d);
void			shortest_ray_prep(t_d *d, double *delta_angle,
					double *len_hray, double *len_vray);
void			choose_shortest_ray(t_d *d, double len_hray,
					double len_vray, int i);
void			shortest_ray(t_d *d, int horizontal_hit,
					int vertical_hit, int i);
void			i_hate_norminette(t_d *d, int *color, int i, int j);
int				is_near_space_is_wall(t_d *d, int i, int j, int lever);
int				four_ifs_for_check_diag(t_d *d, int x, int y, int lever);
int				print_error(void);

#endif