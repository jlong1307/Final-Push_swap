/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:01:04 by jlong             #+#    #+#             */
/*   Updated: 2021/10/28 17:35:10 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

void	five_number(t_state *s)
{
	t_stack	*tmp;

	tmp = s->a;
	find_min(tmp, s);
	move_top(s, s->pos_min);
	tmp = s->a;
	find_min(tmp, s);
	move_top(s, s->pos_min);
	tree_number(s);
	push_in_a(s);
	push_in_a(s);
}

t_state	*tree_number(t_state *s)
{
	find_min(s->a, s);
	find_max(s->a, s);
	if (s->pos_min == 1 && s->pos_max == 2)
		ft_sa(s->a);
	else if (s->pos_max == 0 && s->pos_min == 2)
	{
		ft_sa(s->a);
		ft_rra(s);
	}
	else if (s->pos_min == 1 && s->pos_max == 0)
		ft_ra(s, s->a);
	else if (s->pos_min == 0 && s->pos_max == 1)
	{
		ft_sa(s->a);
		ft_ra(s, s->a);
	}
	else if (s->pos_max == 1 && s->pos_min == 2)
		ft_rra(s);
	return (s);
}
