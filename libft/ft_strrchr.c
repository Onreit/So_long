/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:00:47 by tjalo             #+#    #+#             */
/*   Updated: 2019/10/17 03:36:40 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;

	n = ft_strlen(s);
	while (n > 0 && s[n] != (char)c)
		n--;
	if (s[n] == (char)c)
		return ((char *)&s[n]);
	return (NULL);
}