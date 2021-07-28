/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 22:31:28 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/28 06:35:51 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_texture(t_game *g, t_data *text, char *line)
{
	text->img = mlx_xpm_file_to_image(g->win->mlx_ptr, line,
			&text->width, &text->height);
	if (!text->img)
		exit_failure("Impossible to load texture\n", g);
	text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel,
			&text->line_length, &text->endian);
}

void	get_texture(t_game *g)
{
	set_texture(g, g->col, "./texture/coin.xpm");
	set_texture(g, g->floor, "./texture/sand.xpm");
	set_texture(g, g->text_player, "./texture/mario.xpm");
	set_texture(g, g->exit, "./texture/pipe.xpm");
	set_texture(g, g->wall, "./texture/wall.xpm");
}
