/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:16:40 by jlong             #+#    #+#             */
/*   Updated: 2021/10/20 09:13:09 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

int	digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && !str[1])
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	free_tab(char **tab, int nb_arg)
{
	int	i;

	i = 0;
	while (i < nb_arg)
		free(tab[i++]);
	free(tab);
}

int	error_condition(char *arg[], int i)
{
	int	j;

	j = i + 1;
	if (ft_atoi(arg[i]) > INT_MAX || ft_atoi(arg[i]) < INT_MIN
		|| (!digit(arg[i])))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (arg[j])
	{
		if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_error_one_arg(char *av[])
{
	char	**tab;
	int		nb_arg;
	int		i;

	tab = ft_split(av[1], ' ');
	nb_arg = nbr_word(av[1], ' ');
	i = 0;
	while (i < nb_arg)
	{
		if (error_condition(tab, i))
			return (1);
		i++;
	}
	if (nb_arg == 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	free_tab(tab, nb_arg);
	return (0);
}

int	check_error_multiple_arg(int ac, char *av[])
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (error_condition(av, i))
			return (1);
		i++;
	}
	return (0);
}
