/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sai <aben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:09:53 by aben-sai          #+#    #+#             */
/*   Updated: 2025/01/20 18:13:31 by aben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*mem;
	unsigned char	ch;
	size_t			i;

	i = 0;
	mem = (char *)b;
	ch = (unsigned char)c;
	while (i < len)
	{
		mem[i] = ch;
		++i;
	}
	return (b);
}
