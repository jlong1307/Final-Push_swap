/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:54:07 by jlong             #+#    #+#             */
/*   Updated: 2021/04/12 12:41:30 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*zone1;
	unsigned char	*zone2;

	zone1 = (unsigned char *)src;
	zone2 = (unsigned char *)dst;
	if (!dst && !src)
		return (0);
	while (n > 0)
	{
		*zone2++ = *zone1++;
		n--;
	}
	return (dst);
}
