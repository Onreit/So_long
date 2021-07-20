/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:44:43 by tjalo             #+#    #+#             */
/*   Updated: 2021/06/18 17:56:54 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_freestr(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
	return ;
}

char	*ft_newstr(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	if (s == NULL)
		return (NULL);
	while (i < size)
		s[i++] = 0;
	s[size] = '\0';
	return (s);
}

int	ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_substr(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_freestr(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_freestr(&s[fd]);
		if (ret == 0)
			return (0);
	}
	return (1);
}

int	check(char **s, char **line, int fd, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
	{
		*line = ft_newstr(1);
		return (0);
	}
	return (ft_new_line(s, line, fd, ret));
}

int	get_next_line(int fd, char **line)
{
	static char	*s[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while (1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 1)
			break ;
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_newstr(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (check(s, line, fd, ret));
}
