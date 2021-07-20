/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:28:25 by tjalo             #+#    #+#             */
/*   Updated: 2021/06/18 16:55:19 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*nptr;

	if (!dst && !src)
		return (NULL);
	ptr = (unsigned char *)dst;
	nptr = (unsigned char *)src;
	while (n-- > 0)
		*ptr++ = *nptr++;
	return (dst);
}
