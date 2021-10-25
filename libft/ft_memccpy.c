/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:49:57 by jlong             #+#    #+#             */
/*   Updated: 2021/04/12 12:39:30 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*zsrc;
	unsigned char	*zdst;

	i = 0;
	zsrc = (unsigned char *)src;
	zdst = (unsigned char *)dst;
	while (i < n)
	{
		zdst[i] = zsrc[i];
		if (zsrc[i] == (unsigned char)c)
			return ((void *)&zdst[i + 1]);
		i++;
	}
	return (NULL);
}
