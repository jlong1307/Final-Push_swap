/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_untils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 08:45:48 by jlong             #+#    #+#             */
/*   Updated: 2021/10/28 17:30:29 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

void	ft_add_front(t_stack **alst, t_stack *new)
{
	if (*alst)
	{
		new->next = *alst;
		*alst = new;
	}
	else
		*alst = new;
}

void	delete_nodea(t_state *del)
{
	t_stack	*n;

	n = del->a;
	if (del == NULL)
		return ;
	if (del->a != NULL)
	{
		del->a = del->a->next;
		free(n);
	}
}

void	delete_nodeb(t_state *del)
{
	t_stack	*n;

	n = del->b;
	if (del == NULL)
		return ;
	if (del->b != NULL)
	{
		del->b = del->b->next;
		free(n);
	}
}

void	push_in_a(t_state *p)
{
	t_stack	*x;

	x = add_new_value(p->b->val);
	ft_add_front(&p->a, x);
	delete_nodeb(p);
	write(1, "pa\n", 3);
}
