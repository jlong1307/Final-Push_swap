/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_until.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 08:45:37 by jlong             #+#    #+#             */
/*   Updated: 2021/10/28 18:27:01 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

int	size_stack(t_stack *stc)
{
	int		i;
	t_stack	*tmp;

	tmp = stc;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	find_max(t_stack *s, t_state *stack)
{
	int		max;
	int		i;
	t_stack	*tmp;

	tmp = s;
	i = 0;
	max = tmp->val;
	while (tmp->next != NULL)
	{
		if (tmp->val >= max)
		{
			max = tmp->val;
			stack->pos_max = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (tmp->val >= max)
	{
		max = tmp->val;
		stack->pos_max = i;
	}
	stack->max = max;
}

void	find_min(t_stack *s, t_state *stack)
{
	int		min;
	int		i;
	t_stack	*tmp;

	tmp = s;
	i = 0;
	min = tmp->val;
	stack->pos_min = 0;
	while (tmp->next != NULL)
	{
		if (tmp->val <= min)
		{
			min = tmp->val;
			stack->pos_min = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (tmp->val <= min)
	{
		min = tmp->val;
		stack->pos_min = i;
	}
	stack->min = min;
}

void	set_chunck(t_state *stack)
{
	int	*tab;
	int	nb_chunck;
	int	i;
	int	pos_number;

	tab = ft_sort_int_tab(stack);
	if (size_stack(stack->a) <= 100)
		nb_chunck = 5;
	else
		nb_chunck = 11;
	stack->chunck = malloc((sizeof(int) * (nb_chunck + 1)));
	if (!stack->chunck)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < nb_chunck)
	{
		pos_number = (i + 1) * (size_stack(stack->a) / nb_chunck);
		stack->chunck[i] = tab[pos_number];
		i++;
	}
	stack->chunck[nb_chunck] = 0;
	free (tab);
}

void	nbr_in_fork(t_state *p, int chunck)
{
	t_stack	*tmp;
	int		fork;

	tmp = p->a;
	fork = chunck;
	while (tmp)
	{
		if (tmp->val <= fork)
			p->nbr_in_chunck++;
		tmp = tmp->next;
	}
}
