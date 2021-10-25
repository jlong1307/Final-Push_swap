/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:46:08 by jlong             #+#    #+#             */
/*   Updated: 2021/09/28 16:13:22 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
		res = (res * 10) + str[i++] - '0';
	res = sign * res;
	return (res);
}
