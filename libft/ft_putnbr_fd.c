/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sai <aben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:10:20 by aben-sai          #+#    #+#             */
/*   Updated: 2025/01/20 18:13:32 by aben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		write (fd, "-", 1);
		num *= -1;
	}
	if (num / 10)
		ft_putnbr_fd(num / 10, fd);
	c = num % 10 + '0';
	write (fd, &c, 1);
}
