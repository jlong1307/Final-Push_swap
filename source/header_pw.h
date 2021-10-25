/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_pw.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:11:06 by jlong             #+#    #+#             */
/*   Updated: 2021/10/25 14:58:09 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PW_H
# define HEADER_PW_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}					t_stack;

typedef struct s_state
{
	t_stack		*a;
	t_stack		*b;
	int			len_a;
	int			len_b;
	int			min;
	int			max;
	int			pos_min;
	int			pos_max;
	int			*chunck;
	int			next_chunck;
	int			nbr_in_chunck;
	int			hold_first;
	int			pos_fst;
	int			mid_pos_fst;
	int			hold_second;
	int			pos_sec;
	int			mid_pos_sec;
}				t_state;

int			size_stack(t_stack *stc);
t_stack		*remove_front(t_stack *stack);
void		ft_rrb(t_state *stack);
void		ft_rb(t_state *stack, t_stack *first);
void		op_rrb(t_state *s);
void		op_rb(t_state *s);
void		push_in_a(t_state *p);
int			calmim(t_stack *stack);
void		find_max(t_stack *s, t_state *stack);
t_stack		*add_back(t_stack *stack, int x);
void		ft_free(t_state *stack);
void		free_tab(char **tab, int nb_arg);
int			check_error_multiple_arg(int ac, char *av[]);
int			check_error_one_arg(char *av[]);
void		init_struct(t_state *s);
t_stack		*create_stack_a(t_stack *stack, int argc, char **av);
int			stack_sorted(t_stack *stack);
t_state		*tree_number(t_state *s);
void		five_number(t_state *s);
void		sort(t_state *stack);
void		find_min(t_stack *s, t_state *stack);
void		find_max(t_stack *s, t_state *stack);
void		move_top(t_state *s, int i);
void		ft_sa(t_stack *first);
void		ft_rra(t_state *stack);
t_state		*ft_ra(t_state *s);
void		ft_op_rra(t_state *s, int i);
void		ft_op_ra(t_state *s, int i);
t_stack		*add_new_value(int val);
void		move_to_top(t_state *stack);
void		push_back_in_a(t_state *stack);
int			*ft_sort_int_tab(t_state *stack);
void		find_holdfirst(t_state *s, t_stack *stk, int chunck);
void		find_holdsecond(t_state *s, t_stack *stk, int chunck);
void		same_hold(t_state *s);
void		set_chunck(t_state *stack);
int			big_sort(t_state *stack);
void		nbr_in_fork(t_state *p, int chunck);
void		ft_add_front(t_stack **alst, t_stack *new);
void		delete_nodea(t_state *del);
void		delete_nodeb(t_state *del);
t_stack		*add_back_in_stack(t_stack **stack, int n);
void		check_top_b(t_state *stack);

#endif
