/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:52:05 by tjalo             #+#    #+#             */
/*   Updated: 2021/06/18 16:41:13 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check(char c, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (-1);
}

static size_t	kcehc(char const *set, char const *s)
{
	size_t	i;

	i = ft_strlen(s);
	i--;
	while (check(s[i], set) == 0 && i >= 0)
		i--;
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (check(s1[i], set) == 0 && s1[i])
		i++;
	if (!s1[i])
	{
		str = malloc(sizeof(char));
		*str = '\0';
		return (str);
	}
	str = ft_substr(s1, i, kcehc(set, s1) - i);
	return (str);
}
