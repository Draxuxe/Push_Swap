/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:46:59 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/10 11:57:18 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

t_stack	*pick_index(t_stack *stack, int index)
{
	while (stack)
	{
		if (stack->index >= 0 && stack->index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*pick_value(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	init_indexes(t_stack *stack)
{
	while (stack)
	{
		stack->index = -1;
		stack = stack->next;
	}
}

int	find_next_index(t_stack **stack, int previous)
{
	t_stack	*tmp;
	int		current;

	tmp = *stack;
	current = -200000000;
	while (tmp)
	{
		if (tmp->value > previous
			&& ((current == -200000000 && tmp->value != -200000000)
				|| tmp->value < current))
			current = tmp->value;
		tmp = tmp->next;
	}
	return (current);
}

void	give_index(t_stack *tmp, t_stack **stack)
{
	int			i;
	int			current;
	int			previous;

	i = 1;
	while (tmp)
	{
		if (!pick_index(*stack, i - 1))
		{
			tmp = tmp->next;
			continue ;
		}
		previous = pick_index(*stack, i - 1)->value;
		current = find_next_index(stack, previous);
		if (!pick_value(*stack, current))
		{
			tmp = tmp->next;
			continue ;
		}
		pick_value(*stack, current)->index = i;
		tmp = tmp->next;
		i++;
	}
}
