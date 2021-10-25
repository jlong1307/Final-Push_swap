/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hold.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 08:55:11 by jlong             #+#    #+#             */
/*   Updated: 2021/10/25 14:58:29 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

int	stack_sorted(t_stack *stack)
{
	int	x;

	x = stack->val;
	while (stack->next)
	{
		if (x > stack->next->val)
			return (0);
		x = stack->next->val;
		stack = stack->next;
	}
	return (1);
}

void	same_hold(t_state *stack)
{
	if (stack->pos_fst >= 0)
	{
		if (stack->mid_pos_fst < stack->pos_fst && stack->mid_pos_fst != 0)
		{
			ft_op_rra(stack, stack->mid_pos_sec);
		}
		else
		{
			ft_op_ra(stack, stack->pos_fst);
		}
	}
	else if (stack->mid_pos_sec > 0)
	{
		ft_op_rra(stack, stack->mid_pos_sec);
	}
}

void	find_holdfirst(t_state *s, t_stack *stk, int chunck)
{
	t_stack	*tmp;

	tmp = stk;
	s->pos_fst = 0;
	s->hold_first = tmp->val;
	while (tmp)
	{
		if (s->hold_first <= chunck)
			break ;
		s->hold_first = tmp->next->val;
		s->pos_fst++;
		tmp = tmp->next;
	}
}

void	find_holdsecond(t_state *s, t_stack *stk, int chunck)
{
	t_stack	*tmp;

	tmp = stk;
	s->pos_sec = 0;
	s->hold_second = tmp->val;
	while (tmp)
	{
		if (tmp->val <= chunck)
			s->hold_second = tmp->val;
		tmp = tmp->next;
	}
	tmp = stk;
	while (tmp->val != s->hold_second)
	{
		s->pos_sec++;
		tmp = tmp->next;
	}
}

int	big_sort(t_state *stack)
{
	while (stack->a)
	{
		move_to_top(stack);
	}
	free(stack->chunck);
	push_back_in_a(stack);
	return (1);
}
