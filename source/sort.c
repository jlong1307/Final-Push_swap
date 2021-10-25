/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 08:45:29 by jlong             #+#    #+#             */
/*   Updated: 2021/10/25 14:58:26 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

void	top_of_stack(t_state *stack)
{
	if (stack->hold_first == stack->hold_second)
		same_hold(stack);
	else if (stack->mid_pos_fst == 0 && stack->mid_pos_sec == 0)
	{
		if (stack->pos_fst < stack->pos_sec)
			ft_op_ra(stack, stack->pos_fst);
	}
	else if (stack->pos_fst == stack->mid_pos_sec)
	{
		ft_op_ra(stack, stack->pos_fst);
	}
	else if (stack->mid_pos_fst != 0 && stack->mid_pos_sec != 0)
	{
		if (stack->mid_pos_fst > stack->mid_pos_sec)
			ft_op_rra(stack, stack->mid_pos_sec);
	}
	else if (stack->pos_fst < stack->mid_pos_sec)
		ft_op_ra(stack, stack->pos_fst);
	else if (stack->pos_fst > stack->mid_pos_sec)
		ft_op_rra(stack, stack->mid_pos_sec);
}

int	calmim(t_stack *stack)
{
	int	mid;
	int	total;
	int	modulo;

	total = size_stack(stack);
	mid = total / 2;
	modulo = total % 2;
	mid = mid + modulo;
	return (mid);
}

void	move_to_top(t_state *stack)
{
	int	mid;
	int	total;

	total = size_stack(stack->a);
	stack->mid_pos_fst = 0;
	stack->mid_pos_sec = 0;
	mid = calmim(stack->a);
	if (stack->pos_fst > mid)
		stack->mid_pos_fst = total - stack->pos_fst;
	if (stack->pos_sec > mid)
		stack->mid_pos_sec = total - stack->pos_sec;
	top_of_stack(stack);
}

void	do_sort(t_state *stack)
{
	int	*pchunck;

	pchunck = stack->chunck;
	while (stack->nbr_in_chunck >= 0)
	{
		if (stack->nbr_in_chunck == 0)
		{
			++pchunck;
			nbr_in_fork(stack, *pchunck);
			if (*pchunck == 0)
			{
				if (big_sort(stack))
					return ;
			}
		}
		else
		{
			find_holdfirst(stack, stack->a, *pchunck);
			find_holdsecond(stack, stack->a, *pchunck);
			move_to_top(stack);
			stack->nbr_in_chunck--;
		}
	}
}

void	sort(t_state *stack)
{
	set_chunck(stack);
	nbr_in_fork(stack, *stack->chunck);
	do_sort(stack);
}
