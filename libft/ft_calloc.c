/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:27:18 by jlong             #+#    #+#             */
/*   Updated: 2021/04/13 19:05:36 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned int	a;
	unsigned int	b;

	a = (unsigned int)nmemb;
	b = (unsigned int)size;
	if (nmemb == 0 || size == 0)
	{
		a = 1;
		b = 1;
	}
	ptr = (void *)malloc(a * b);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, a * b);
	return (ptr);
}
