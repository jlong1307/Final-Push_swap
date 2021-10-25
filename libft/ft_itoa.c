/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:20:50 by jlong             #+#    #+#             */
/*   Updated: 2021/04/13 17:34:34 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n <= 9)
		return (1);
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		i;
	int		len;
	char	*s;

	i = -1;
	sign = 0;
	len = ft_len(n);
	if (n < 0)
		sign = 1;
	s = (char *)malloc(sizeof(char) * (len + sign + 1));
	if (!s)
		return (NULL);
	while (++i < len)
	{
		if (!sign)
			s[len - 1 - i] = n % 10 + '0';
		else
			s[len - i] = (10 - (n % 10)) + '0' - 10;
		n = n / 10;
	}
	if (sign)
		s[0] = '-';
	s[len + sign] = 0;
	return (s);
}
