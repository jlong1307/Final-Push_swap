/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:13:53 by jlong             #+#    #+#             */
/*   Updated: 2021/04/13 16:26:40 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1[++i] != '\0')
	{
		dst[++j] = s1[i];
	}
	i = -1;
	while (s2[++i] != '\0')
	{
		dst[++j] = s2[i];
	}
	dst[++j] = '\0';
	return (dst);
}
