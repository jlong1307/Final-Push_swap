/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:56:59 by jlong             #+#    #+#             */
/*   Updated: 2021/04/07 15:56:52 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	size_d;
	unsigned int	size_s;

	size_d = ft_strlen(dst);
	size_s = ft_strlen(src);
	if (dstsize <= size_d)
		return (size_s + dstsize);
	while (*dst)
		dst++;
	i = 0;
	while ((i < dstsize - size_d - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size_d + size_s);
}
