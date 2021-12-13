/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:11:49 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/13 12:43:28 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	get_lowest_top(t_stack **a, int index, int i)
{
	if (index == 0)
		return ;
	else if (index == 1)
	{
		rotate(a, 'a');
		return ;
	}
	else if (index == 2)
	{
		rotate(a, 'a');
		rotate(a, 'a');
		return ;
	}
	else if (index == 3 - i)
	{
		reverse_rotate(a, 'a');
		reverse_rotate(a, 'a');
		return ;
	}
	if (index == 4 - i)
	{
		reverse_rotate(a, 'a');
		return ;
	}
}

int	is_sorted(t_stack *stack)
{
	int	last;

	last = stack->value;
	while (stack->next)
	{
		if (stack->value > stack->next->value
			|| last > stack->value)
			return (0);
		last = stack->value;
		stack = stack->next;
	}
	return (1);
}

void	good_sort(t_stack **stack_a, t_stack **stack_b)
{
	if ((get_top(*stack_b) > get_top(*stack_a))
		&& get_top(*stack_b) < get_bottom(*stack_a))
	{
		while (get_top(*stack_b) > get_top(*stack_a))
			rotate(stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	if ((get_top(*stack_b) < get_top(*stack_a))
		&& get_top(*stack_b) < get_bottom(*stack_a))
	{
		while (!is_sorted(*stack_a))
			reverse_rotate(stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	if ((get_top(*stack_b) < get_top(*stack_a))
		&& get_top(*stack_b) > get_bottom(*stack_a))
	{
		push(stack_b, stack_a, 'a');
		while (!is_sorted(*stack_a))
			rotate(stack_a, 'a');
	}
	if (get_top(*stack_a) > get_second(*stack_a))
		swap(stack_a, 'a');
}

int	get_bigger_index(t_stack **x, int y)
{
	int	i;

	i = 0;
	while (*x)
	{
		if ((*x)->value == y)
			break ;
		i ++;
		(*x) = (*x)->next;
	}
	return (i);
}
