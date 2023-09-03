/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:46:47 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/02 19:21:17 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "../../minilibx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <math.h>
# include <stdint.h>

# define UI_MAX 4294967295
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307

typedef struct s_data {
	void			*img;
	void			*img_0;
	void			*img_1;
	void			*img_p;
	void			*img_c;
	void			*img_b;
	void			*img_e;
	void			*img_end;
	char			*addr;
	int				img_x;
	int				img_y;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*win;
	int				dir;
	int				left;
	int				right;
	int				up;
	int				down;
	int				size;
	unsigned int	color;
	char			**map;
	char			**copy_map;
	int				items;
	int				play_x;
	int				play_y;
	int				width;
	int				height;
	int				usable;
	int				moves;
	int				victory;
	int				level;
}				t_data;

int				main(int ac, char **av);
int				ft_strcmp(char *str, char *str2);
int				arg_parsing(int ac, char **av, t_data *data);
int				deal_key(t_data *data);
int				key_release(int key, t_data *data);
int				key_pressed(int key, t_data *data);
int				ft_destroy_windows(t_data *data);
unsigned int	new_color(t_data *data);
char			**ft_split_read(char *str);
char			*ft_calloc(size_t count, size_t size);
void			*ft_bzero(void *s, size_t n);
int				check_map(char *name, t_data *data);
int				ft_strlen(char *str);
int				ft_tablen(char **tab);
int				check_walls(char **tab);
int				flood_fill(t_data *data);
void			flood_test(t_data *data, char **tab, int x, int y);
int				check_cep(char **tab, t_data *data, int i, int y);
void			print_map(char **tab);
char			*ft_strjoin(char *s1, char *s2);
char			*get_string_map(int fd);
void			ft_free(char *str, char *str2);
void			ft_free_tab(char **tab, char **tab2);
char			*ft_strdup(char *str);
void			create_window(t_data *data, char *name);
void			start_mlx(t_data *data);
void			create_image(t_data *data);
void			put_map(t_data *data);
void			sprite_to_win(t_data *data, char sign, int x, int y);
void			put_player(t_data *data);
void			move_player(t_data *data, int x, int y);
void			show_victory(t_data *data);
void			ft_malloc_error(t_data *data, char *str, char **tab);
char			**compute_minimap(t_data *data, int x, int y, int mix);
void			set_imgs(t_data *data);
void			print_error(char *str);
int				ecp_values(int e, int c, int p);
int				is_ecp(char sign);
void			start(void);

#endif