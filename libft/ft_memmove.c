/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:28:31 by tjalo             #+#    #+#             */
/*   Updated: 2019/10/25 04:19:04 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr;
	char	*nptr;
	size_t	i;

	ptr = (char *)dest;
	nptr = (char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (nptr < ptr)
		while (++i <= n)
			ptr[n - i] = nptr[n - i];
	else
		while (n-- > 0)
			*ptr++ = *nptr++;
	return (dest);
}
