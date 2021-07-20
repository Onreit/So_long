/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:19:33 by tjalo             #+#    #+#             */
/*   Updated: 2021/01/06 12:19:38 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		size;
	long	nbr;

	nbr = (int)n;
	size = 1;
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	while (nbr / size >= 10)
		size *= 10;
	while (size >= 1)
	{
		ft_putchar(nbr / size + '0');
		nbr %= size;
		size /= 10;
	}
}
