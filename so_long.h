/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:22:45 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/21 00:00:10 by tjalo            ###   ########.fr       */
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

typedef struct s_game
{
	t_map		*map;
	t_win		*win;
	t_color		*color;
	t_data		*data;
	double		pos_x;
	double		pos_y;
	int			collect;
	int			current_move;
}				t_game;


#endif