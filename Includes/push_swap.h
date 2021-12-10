/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:26:00 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/10 17:47:09 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../Libft/libft.h"
# include "../Get_next_line/get_next_line.h"

/* STACK STRUCT */

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}			t_stack;

/* FUNCTIONS SORTING */

	/*REVERSEROTATE*/

void	reverse_rotate_quiet(t_stack **rrotated);
void	reverse_rotate(t_stack **rrotated, char c);
void	double_reverse_rotate(t_stack **a, t_stack **b);

	/*ROTATE*/

void	rotate_quiet(t_stack **rotated);
void	rotate(t_stack **rotated, char c);
void	double_rotate(t_stack **a, t_stack **b);

	/*SWAP*/

void	swap_quiet(t_stack **swapped);
void	swap(t_stack **swapped, char c);
void	double_swap(t_stack **a, t_stack **b);

	/*PUSH*/

void	push_quiet(t_stack **original, t_stack **copy);
void	push(t_stack **original, t_stack **copy, char c);

/* PARSING */

void	parser(t_stack **a, char **av, int ac);
int		ft_stackparse(t_stack *alst, t_stack *new);
t_stack	*new_elem(t_stack *a, int new);

/* SORTING */

void	sort(t_stack **stack_a, t_stack **stack_b);
void	pre_sort(t_stack **stack);

/* UTILS*/

	/*STACKS*/
int		stack_size(t_stack **stack);
void	clear_stacks(t_stack **stack_a, t_stack **stack_b);
t_stack	*get_last_element(t_stack *lst);
t_stack	*get_element(t_stack *lst, int index);
t_stack	*ft_stacknew(int value);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stackadd_back(t_stack **alst, t_stack *new);
	/*OPTI*/
void	move_opti_b(t_stack **needed, t_stack **perhaps, char func, char stack);
void	move_opti_a(t_stack **a, t_stack **b, char func, char stack);
void	move_opti_rra(t_stack **b, t_stack **a, char *func, char stack);
void	move_opti_rrb(t_stack **b, t_stack **a, char *func, char stack);
void	move_opti(t_stack **a, int i);
void	sort_3_for_5(t_stack **stack_a);
	/*SORTS*/
int		is_sorted(t_stack *stack);
void	good_sort(t_stack **stack_a, t_stack **stack_b);
void	give_index(t_stack *tmp, t_stack **stack);
int		find_next_index(t_stack **stack, int previous);
void	init_indexes(t_stack *stack);
void	get_lowest_top(t_stack **a, int index, int i);
	/*GET*/
t_stack	*get_lowest(t_stack *stack);
int		get_bigger(t_stack *stack);
int		get_bottom(t_stack *stack);
int		get_top(t_stack *stack);
int		get_second(t_stack *stack);
	/*ELSE*/
void	print_list(t_stack *x);

/* CHECKER */

void	dispatch_command(char *cmd, t_stack **stack_a, t_stack **stack_b);
void	handle_standard_input(t_stack *stack_a, t_stack *stack_b);

#endif