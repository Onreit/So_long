/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:02:25 by tjalo             #+#    #+#             */
/*   Updated: 2021/06/18 16:48:54 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*aoti(char *str, int nb, int size)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		str[0] = '-';
		i++;
		nb = -nb;
	}
	while (nb / size >= 10)
		size *= 10;
	while (size > 0)
	{
		str[i] = (nb / size) + '0';
		nb %= size;
		size /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	len(int nb)
{
	int	i;
	int	nbr;

	i = 0;
	if (nb < 0)
	{
		nbr = -nb;
		i++;
	}
	else
		nbr = nb;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * (len(n) + 1));
	if (!str)
		return (NULL);
	str = aoti(str, n, 1);
	return (str);
}
