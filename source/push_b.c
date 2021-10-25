/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:27:22 by jlong             #+#    #+#             */
/*   Updated: 2021/09/30 11:13:20 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

void	push_in_b(t_state *p)
{
	t_stack	*s;

	s = add_new_value(p->a->val);
	ft_add_front(&p->b, s);
	delete_nodea(p);
	write(1, "pb\n", 3);
}

void	ft_rb(t_state *stack, t_stack *first)
{
	add_back_in_stack(&stack->b, first->val);
	delete_nodeb(stack);
	write(1, "rb\n", 3);
}

void	ft_rrb(t_state *stack)
{
	t_stack	*lst;
	t_stack	*new_lst;

	lst = stack->b;
	while (lst->next)
	{
		if (!lst->next->next)
			new_lst = lst;
		lst = lst->next;
	}
	new_lst->next = NULL;
	lst->next = stack->b;
	stack->b = lst;
	write(1, "rrb\n", 4);
}

int	check_stack_bigger(t_state *stack)
{
	t_stack	*b;

	b = stack->b;
	while (b)
	{
		if (stack->a->val < stack->b->val)
		{
			return (0);
		}
		b = b->next;
	}
	return (1);
}

void	check_top_b(t_state *stack)
{
	int	size;

	size = size_stack(stack->b);
	if (!stack->b)
		push_in_b(stack);
	else
		push_in_b(stack);
}
