/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:10:38 by jlong             #+#    #+#             */
/*   Updated: 2021/04/13 16:28:55 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*dst;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		dst = malloc(sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (++i - 1 < len)
		*(dst + i - 1) = *(s + start + i - 1);
	*(dst + i - 1) = '\0';
	return (dst);
}
