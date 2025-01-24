/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sai <aben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:07:29 by aben-sai          #+#    #+#             */
/*   Updated: 2025/01/20 18:07:49 by aben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*srce;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = srce[i];
		++i;
	}
	return (dst);
}
