/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:04:55 by jlong             #+#    #+#             */
/*   Updated: 2021/10/20 08:56:00 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_word(char const *str, char c)
{
	int	i;
	int	nb_words;

	i = 1;
	nb_words = 0;
	if (str[0] == 0)
		return (0);
	if (!c)
		return (1);
	if (str[0] != c)
		nb_words = 1;
	while (str[i])
	{
		if (str[i - 1] == c && str[i] != c)
			nb_words++;
		i++;
	}
	return (nb_words);
}

static char	**malloc_error(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	size_word(char const *str, char c, int i)
{
	int	count;

	count = 0;
	while (str[i] == c && str[i] != '\0')
	{
		i++;
	}
	while (str[i] != '\0' && str[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**fill_tab(char const *str, char c, char **res, int nb_words)
{
	int		i;
	int		index;
	int		j;

	i = 0;
	index = 0;
	while (index < nb_words)
	{
		j = 0;
		res[index] = malloc(sizeof(char) * (size_word(str, c, i) + 1));
		if (!res[index])
			return (malloc_error(res));
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
			res[index][j++] = str[i++];
		res[index][j] = '\0';
		index++;
	}
	res[index] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nb_words;

	if (!s)
		return (NULL);
	nb_words = nbr_word(s, c);
	res = malloc(sizeof(char *) * (nb_words + 1));
	if (!res)
		return (NULL);
	res = fill_tab(s, c, res, nb_words);
	return (res);
}
