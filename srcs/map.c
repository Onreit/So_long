/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:24:06 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/28 07:59:26 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	parse_info(t_game *game)
{
	int		i;

	i = 0;
	while (game->map->tmp_map[i])
	{
		if (game->map->tmp_map[i] != 'C' && game->map->tmp_map[i] != '1'
			&& game->map->tmp_map[i] != '0' && game->map->tmp_map[i] != '\n'
			&& game->map->tmp_map[i] != 'P' && game->map->tmp_map[i] != 'E')
			exit_failure("Invalid map\n", game);
		i++;
	}
}

void	parse_map(char *line, t_game *game)
{
	int	i;

	ft_strjoin_fr(&(game->map->tmp_map), line);
	ft_strjoin_fr(&(game->map->tmp_map), "\n");
	i = -1;
	while (line[++i])
	{
		if (line[i] == 'P')
		{
			if (game->player->dir == '0')
				game->player->dir = line[i];
		}
	}
}

static void	get_map(char *line, t_game *game)
{
	if (game->map_started == 0 && ft_isempty(line))
	{
		free(line);
		exit_failure("The map has a wrong format\n", game);
	}
	if (game->map_started == 1)
	{
		if (game->map_stopped == 1 && !ft_isempty(line))
		{
			free(line);
			exit_failure("The map has a wrong format\n", game);
		}
		else
			help_map(game, line);
	}
	else
	{
		if (ft_isrow(line))
		{
			game->map_started = 1;
			parse_map(line, game);
		}
	}
}

void	read_map(char *map_path, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_failure("The file doesn't exist;\n", game);
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			get_map(line, game);
			free(line);
		}
		get_map(line, game);
		free(line);
		parse_info(game);
		get_disp(game);
		check_info(game);
		check_map(game, game->map, game->player);
		is_rect(game);
		game->win->width = game->map->nb_col * game->size;
		game->win->height = game->map->nb_row * game->size;
	}
}
