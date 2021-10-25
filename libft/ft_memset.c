/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:46:39 by jlong             #+#    #+#             */
/*   Updated: 2021/04/07 14:56:52 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ps;

	i = 0;
	ps = (unsigned char *)s;
	while (i < n)
		ps[i++] = (unsigned char)c;
	s = (void *)ps;
	return (s);
}
