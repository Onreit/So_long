/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 22:08:57 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/28 05:28:47 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Retourne la couleur d'un pixel dans une image
**
**    @param        data        image
**    @param        x            coordonné du pixel en x;
**    @param        y            coordonné du pixel en y;
**    @ret        int            Couleur
*/

int	*get_pixel_img(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	return ((int *)dst);
}

/* Retourne la position du pixel a aller chercher dans la textures
**
**    @param        sizetext        taille de la texture
**    @param        pos                coordonné du pixel;
**    @param        size            taille des cases;
**    @ret        int                Couleur
*/

int	get_pos_in_text(int sizetext, int pos, int size)
{
	float	scale;

	if (size > sizetext)
		scale = ((float)size / (float)sizetext);
	if (size <= sizetext)
		scale = ((float)sizetext / (float)size);
	return (((int)((float)pos * scale) % sizetext));
}

/*void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}*/

void	draw_texture(t_game *g, t_data *texture)
{
	int	px;
	int	py;
	int	color;

	px = g->x * g->size;
	py = g->y * g->size;
	while (px <= (g->x + 1) * g->size)
	{
		py = g->y * g->size;
		while (py <= (g->y + 1) * g->size)
		{
			color = *get_pixel_img(texture,
					get_pos_in_text(texture->width,
						px % g->size, g->size),
					get_pos_in_text(texture->height,
						py % g->size, g->size));
			if (color != 0x000000)
				my_mlx_pixel_put(g->data, px, py, color);
			py++;
		}
		px++;
	}
}
