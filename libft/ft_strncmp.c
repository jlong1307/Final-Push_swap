/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:54:21 by jlong             #+#    #+#             */
/*   Updated: 2021/04/14 15:20:35 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (us1[i] || us2[i]))
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}
