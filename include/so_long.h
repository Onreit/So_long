/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:22:45 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/23 06:31:30 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_win
{
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_win

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*path;
	int		width;
	int		height;
}				t_data;

typedef struct s_map
{
	int		nb_row;
	int		nb_col;
	int		**l_map;
	char	*tmp_map;
	char	*tmp_file;
}				t_map;

typedef struct s_game
{
	t_map		*map;
	t_win		*win;
	t_data		*data;
	double		pos_x;
	double		pos_y;
	int			collect;
	int			check_exit;
	int			current_move;
}				t_game;

void	mini_map(t_game *game);
void	exit_failure(char *error, t_game *g);
void	clear_game(t_game *g);
int	exit_game(t_game *g);
int	main_loop(t_game *g);
void	init_game(t_game *gamer);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	read_map(char *map_path, t_game *game);
int	*handle_line(char *line, t_game *game, int current_line);
void	ft_strjoin_fr(char **str, char *buf);
void	check_map(t_game *g, t_map *map, t_player *player);
void	free_split(char **str);
int	ft_isrow(char *row);
int	ft_isempty(char *line);
void	check_info(t_game *g);
void	print_map(int **map, int nb_row, int nb_col);
void	clear_image(t_game *g);
void	position(t_player *player, float posX, float posY);

#endif