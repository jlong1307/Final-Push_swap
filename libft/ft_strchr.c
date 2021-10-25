/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:47:56 by jlong             #+#    #+#             */
/*   Updated: 2021/04/16 15:02:47 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*ss;

	ss = (unsigned char *)s;
	i = -1;
	while (++i < ft_strlen(s))
		if (ss[i] == (char)c)
			return ((char *)&ss[i]);
	if (ss[i] == (char)c)
		return ((char *)&ss[i]);
	return (NULL);
}
