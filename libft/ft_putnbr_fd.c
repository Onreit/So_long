/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:46:29 by tjalo             #+#    #+#             */
/*   Updated: 2019/10/16 23:01:08 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		size;
	long	nbr;

	nbr = (int)n;
	size = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	while (nbr / size >= 10)
		size *= 10;
	while (size >= 1)
	{
		ft_putchar_fd((nbr / size + '0'), fd);
		nbr %= size;
		size /= 10;
	}
}
