/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_untils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:27:44 by jlong             #+#    #+#             */
/*   Updated: 2021/10/20 09:09:30 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

void	init_struct(t_state *s)
{
	s->a = NULL;
	s->b = NULL;
	s->len_a = 0;
	s->len_b = 0;
	s->chunck = NULL;
	s->min = 0;
	s->max = 0;
	s->pos_min = 0;
	s->pos_max = 0;
	s->chunck = 0;
	s->next_chunck = 0;
	s->nbr_in_chunck = 0;
	s->hold_first = 0;
	s->pos_fst = 0;
	s->mid_pos_fst = 0;
	s->hold_second = 0;
	s->pos_sec = 0;
	s->mid_pos_sec = 0;
}

t_stack	*free_list(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	if (temp)
		free(temp);
	return (stack);
}

void	ft_free(t_state *stack)
{
	if (stack->a)
		free_list(stack->a);
	if (stack->b)
		free_list(stack->b);
	if (stack)
		free(stack);
}

int	*put_in_tab(t_state *stack)
{
	int		*tab;
	int		i;
	t_stack	*temp;

	tab = malloc(sizeof(int) * size_stack(stack->a) + 1);
	if (!tab)
		exit (EXIT_FAILURE);
	i = 0;
	temp = stack->a;
	while (temp)
	{
		tab[i] = temp->val;
		i++;
		temp = temp->next;
	}
	tab[i] = '\0';
	return (tab);
}

int	*ft_sort_int_tab(t_state *stack)
{
	int	i;
	int	j;
	int	temp;
	int	*tab;

	j = 0;
	tab = put_in_tab(stack);
	i = 0;
	while (j < size_stack(stack->a) - 1)
	{
		i = 0;
		while (i < size_stack(stack->a) - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
	return (tab);
}
