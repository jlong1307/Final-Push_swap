/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:06:25 by jlong             #+#    #+#             */
/*   Updated: 2021/10/28 17:37:22 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

t_stack	*add_back(t_stack *stack, int x)
{
	t_stack	*element;
	t_stack	*temp;

	element = malloc(sizeof(t_stack));
	if (!element)
		exit(EXIT_FAILURE);
	element->val = x;
	element->next = NULL;
	if (!stack)
		return (element);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	temp->next = element;
	return (stack);
}

void	ft_sa(t_stack *first)
{
	int	tmp;

	tmp = first->val;
	first->val = first->next->val;
	first->next->val = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *first)
{
	int	tmp;

	tmp = first->val;
	first->val = first->next->val;
	first->next->val = tmp;
	write(1, "sb\n", 3);
}

void	ft_ra(t_state *stack, t_stack *first)
{
	add_back_in_stack(&stack->a, first->val);
	delete_nodea(stack);
	write(1, "ra\n", 3);
}

void	ft_rra(t_state *stack)
{
	t_stack	*lst;
	t_stack	*new_lst;

	lst = stack->a;
	while (lst->next)
	{
		if (!lst->next->next)
			new_lst = lst;
		lst = lst->next;
	}
	new_lst->next = NULL;
	lst->next = stack->a;
	stack->a = lst;
	write(1, "rra\n", 4);
}
