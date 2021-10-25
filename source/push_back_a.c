/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:29:59 by jlong             #+#    #+#             */
/*   Updated: 2021/09/28 14:30:44 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

void	ft_op_rrb(t_state *s, int i)
{
	if (i == 0)
	{
		ft_rrb(s);
		push_in_a(s);
	}
	else
	{	
		while (i > 0)
		{
			ft_rrb(s);
			i--;
		}
		push_in_a(s);
	}
}

void	ft_op_rb(t_state *s, int i)
{
	if (i == 0)
		push_in_a(s);
	else
	{
		while (i > 0)
		{
			ft_rb(s, s->b);
			i--;
		}
		push_in_a(s);
	}
}

void	move_to_top_b(t_state *stack, int i)
{
	int	mid;
	int	size;

	size = size_stack(stack->b);
	mid = calmim(stack->b);
	if (i < mid)
		ft_op_rb(stack, i);
	else
	{
		i = size - i;
		ft_op_rrb(stack, i);
	}
}

void	push_back_in_a(t_state *stack)
{
	while (stack->b)
	{
		find_max(stack->b, stack);
		move_to_top_b(stack, stack->pos_max);
	}
}
