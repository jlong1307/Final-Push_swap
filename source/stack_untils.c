/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_untils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:15:46 by jlong             #+#    #+#             */
/*   Updated: 2021/10/20 09:00:53 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_pw.h"

t_stack	*add_new_value(int val)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		return (NULL);
	}
	new->val = val;
	new->next = NULL;
	return (new);
}

t_stack	*get_last_node(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s);
}

void	push_back_in_stack(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = get_last_node(*stack);
	last->next = new;
}

t_stack	*add_back_in_stack(t_stack **stack, int n)
{
	t_stack	*new;

	new = add_new_value(n);
	if (!new)
	{
		return (NULL);
	}
	push_back_in_stack(stack, new);
	return (*stack);
}

t_stack	*create_stack_a(t_stack *stack, int argc, char **av)
{
	int		i;
	char	**tab;
	int		nb_arg;

	i = 0;
	tab = ft_split(av[1], ' ');
	if (!tab)
		exit (EXIT_FAILURE);
	nb_arg = nbr_word(av[1], ' ');
	if (argc == 2)
	{
		while (i < nb_arg)
			stack = add_back(stack, ft_atoi(tab[i++]));
	}
	else
	{
		i = 1;
		while (i < argc)
			stack = add_back(stack, ft_atoi(av[i++]));
	}
	free_tab(tab, nb_arg);
	return (stack);
}
