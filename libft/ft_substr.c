/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:05:49 by tjalo             #+#    #+#             */
/*   Updated: 2021/06/18 16:42:08 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*tmp;

	str = malloc(sizeof(char) * len + 1);
	if (!str || !s)
		return (NULL);
	if (!len || start >= (unsigned int)ft_strlen(s))
	{
		*str = '\0';
		return (str);
	}
	tmp = str;
	while (len > 0 && s[start])
	{
		*str = s[start];
		start++;
		str++;
		len--;
	}
	*str = '\0';
	return (tmp);
}
