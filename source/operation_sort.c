/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:02:07 by jlong             #+#    #+#             */
/*   Updated: 2021/09/29 11:34:05 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

void	ft_op_ra(t_state *s, int i)
{
	if (i == 0)
		check_top_b(s);
	else
	{
		while (i > 0)
		{
			ft_ra(s);
			i--;
		}
		check_top_b(s);
	}
}

void	ft_op_rra(t_state *s, int i)
{
	if (i == 0)
	{
		ft_rra(s);
		check_top_b(s);
	}
	else
	{	
		while (i > 0)
		{
			ft_rra(s);
			i--;
		}
		check_top_b(s);
	}
}

void	op_rrb(t_state *s)
{
	int	mid_second;

	mid_second = s->mid_pos_fst;
	if (mid_second == 1)
	{
		ft_rrb(s);
		push_in_a(s);
	}
	else
	{	
		while (mid_second > 0)
		{
			ft_rrb(s);
			mid_second--;
		}
		push_in_a(s);
	}
}

void	op_rb(t_state *s)
{
	int	first_top;

	first_top = s->pos_fst;
	if (first_top == 0)
	{
		push_in_a(s);
	}
	else
	{
		while (first_top > 0)
		{
			ft_rb(s, s->a);
			first_top--;
		}
		push_in_a(s);
	}
}

void	move_top(t_state *s, int i)
{
	int	mid;
	int	size;

	size = size_stack(s->a);
	mid = calmim(s->a);
	if (i < mid)
	{
		ft_op_ra(s, i);
	}
	else
	{
		i = size - i;
		ft_op_rra(s, i);
	}
}
