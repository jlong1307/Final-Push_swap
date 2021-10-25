/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:17:31 by jlong             #+#    #+#             */
/*   Updated: 2021/04/13 16:52:23 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			j;
	size_t			i;

	i = 0;
	if (!set || !s1)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	j = ft_strlen(&s1[i]);
	if (j != 0)
		while (s1[i + j - 1] && ft_strchr(set, s1[i + j - 1]) != NULL)
			j--;
	return (ft_substr(s1, i, j));
}
