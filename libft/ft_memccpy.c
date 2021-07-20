/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:41:24 by tjalo             #+#    #+#             */
/*   Updated: 2019/10/25 01:19:25 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*nptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)d;
	nptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = nptr[i];
		if (ptr[i] == (unsigned char)c)
		{
			i++;
			return (&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
