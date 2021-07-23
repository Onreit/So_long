/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:19:11 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/23 06:21:53 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_disp(t_game *game)
{
	char		**split_map;
	t_map		*map;
	int			i;

	map = game->map;
	split_map = ft_split(map->tmp_map, '\n');
	while (split_map[(int)map->nb_row])
	{
		if (map->nb_col < (int)ft_strlen(split_map[map->nb_row]))
			map->nb_col = (int)ft_strlen(split_map[map->nb_row]);
		map->nb_row++;
	}
	map->l_map = (int **)malloc(map->nb_row * sizeof(int *));
	if (!map->l_map)
		return ;
	i = 0;
	while (i < map->nb_row)
	{
		map->l_map[i] = handle_line(split_map[i], game, i);
		i++;
	}
	free_split(split_map);
}

void	reset_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->nb_row)
	{
		x = 0;
		while (x < map->nb_col)
		{
			if (map->l_map[y][x] == 9)
				map->l_map[y][x] = 0;
			if (map->l_map[y][x] == 8)
				map->l_map[y][x] = 2;
			if (map->l_map[y][x] == 7)
				map->l_map[y][x] = 3;
			x++;
		}
		y++;
	}
}

void	flood_fill(t_game *g, t_map map, int pos_x, int pos_y)
{
	if (pos_y >= (int)map.nb_row || pos_y < 0)
		exit_failure("The map is not close;\n", g);
	else if (pos_x >= (int)map.nb_col || pos_x < 0)
		exit_failure("The map is not close;\n", g);
	else if (map.l_map[pos_y][pos_x] != 1 && map.l_map[pos_y][pos_x] != 9
		&& map.l_map[pos_y][pos_x] != 0 && map.l_map[pos_y][pos_x] != 2
		&& map.l_map[pos_y][pos_x] != 3  && map.l_map[pos_y][pos_x] != 8
		&& map.l_map[pos_y][pos_x] != 7)
		exit_failure("The map is invalid;\n", g);
	else if (map.l_map[pos_y][pos_x] == 1 || map.l_map[pos_y][pos_x] == 9
		|| (map.l_map[pos_y][pos_x] != 0 && map.l_map[pos_y][pos_x] != 2
		&& map.l_map[pos_y][pos_x] != 3))
		return ;
	if (map.l_map[pos_y][pos_x] == 0)
		map.l_map[pos_y][pos_x] = 9;
	if (map.l_map[pos_y][pos_x] == 2)
		map.l_map[pos_y][pos_x] = 8;
	if (map.l_map[pos_y][pos_x] == 3)
		map.l_map[pos_y][pos_x] = 7;
	flood_fill(g, map, pos_x + 1, pos_y);
	flood_fill(g, map, pos_x - 1, pos_y);
	flood_fill(g, map, pos_x, pos_y + 1);
	flood_fill(g, map, pos_x, pos_y - 1);
}

void	check_map(t_game *g, t_map *map, t_player *player)
{
	if (map->nb_row < 3 || map->nb_col < 3)
		exit_failure("The map is too small;\n", g);
	if (player->posY >= (int)map->nb_row || player->posY < 0)
		exit_failure("The coordinates are wrong;\n", g);
	if (player->posX >= (int)map->nb_col || player->posX < 0)
		exit_failure("The coordinates are wrong;\n", g);
	flood_fill(g, *(map), (int)player->posX, (int)player->posY);
	reset_map(map);
}

void	free_split(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		free(str[len++]);
	free(str);
}