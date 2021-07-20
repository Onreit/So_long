/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 01:19:00 by tjalo             #+#    #+#             */
/*   Updated: 2021/06/18 16:51:14 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr;
	char	*nptr;

	ptr = (char *)s1;
	nptr = (char *)s2;
	if (n <= 0)
		return (0);
	while (--n && *ptr == *nptr)
	{
		ptr++;
		nptr++;
	}
	return (*(unsigned char *)ptr - *(unsigned char *)nptr);
}
