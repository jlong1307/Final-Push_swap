/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:13:42 by jlong             #+#    #+#             */
/*   Updated: 2021/10/28 18:03:08 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

int	check_error(int ac, char *av[])
{
	if (ac == 2)
	{
		if (check_error_one_arg(av))
			return (1);
	}
	else
	{
		if (check_error_multiple_arg(ac, av))
			return (1);
	}
	return (0);
}

int	main(int argc, char **av)
{
	t_state	*stack;
	int		size;

	if (argc == 1 || check_error(argc, av))
		return (-1);
	stack = (t_state *)malloc(sizeof(t_state));
	if (!stack)
		exit(EXIT_FAILURE);
	init_struct(stack);
	stack->a = create_stack_a(stack->a, argc, av);
	size = size_stack(stack->a);
	if (stack_sorted(stack->a))
	{
		ft_free(stack);
		return (0);
	}
	if (size == 3)
		stack = tree_number(stack);
	else if (size == 5)
		five_number(stack);
	else
		sort(stack);
	ft_free(stack);
	return (0);
}
