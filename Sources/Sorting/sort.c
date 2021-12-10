/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:00:14 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/10 17:53:59 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	sort_3(t_stack **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = get_top(*stack_a);
	middle = get_element(*stack_a, 1)->value;
	bottom = get_bottom(*stack_a);
	if (top > middle && bottom > middle && top < bottom)
		swap(stack_a, 'a');
	else if (top > middle && middle > bottom && top > bottom)
	{
		swap(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if (top > middle && bottom > middle && top > bottom)
		rotate(stack_a, 'a');
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (top < middle && middle > bottom && top > bottom)
		reverse_rotate(stack_a, 'a');
}

void	sort_5(t_stack **a, t_stack **b)
{
	pre_sort(a);
	if (stack_size(a) == 5)
	{
		move_opti(a, 0);
		push(a, b, 'b');
		move_opti(a, 1);
		push(a, b, 'b');
		sort_3(a);
		push(b, a, 'a');
		push(b, a, 'a');
		if (!is_sorted(*a))
			rotate(a, 'a');
	}
	else
	{
		move_opti(a, 0);
		push(a, b, 'b');
		sort_3(a);
		push(b, a, 'a');
	}
}

void	pre_sort(t_stack **stack)
{
	t_stack	*tmp;

	init_indexes(*stack);
	get_lowest(*stack)->index = 0;
	tmp = *stack;
	give_index(tmp, stack);
	tmp = *stack;
	while (tmp)
	{
		tmp->value = tmp->index;
		tmp = tmp->next;
	}
}

void	sort_else(t_stack **stack_a, t_stack **stack_b)
{
	size_t		length;
	size_t		i;
	size_t		j;
	int			k;

	length = stack_size(stack_a);
	i = 0;
	pre_sort(stack_a);
	while (is_sorted(*stack_a) == 0)
	{
		j = 0;
		while (j < length)
		{
			k = (*stack_a)->value >> i;
			if ((k & 1) == 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			j++;
		}
		while ((*stack_b))
			push(stack_b, stack_a, 'a');
		i++;
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	length;

	length = stack_size(stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (length == 2)
		swap(stack_a, 'a');
	else if (length == 3)
		sort_3(stack_a);
	else if (length <= 5)
		sort_5(stack_a, stack_b);
	else if (length > 5)
		sort_else(stack_a, stack_b);
}
