/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:08:07 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/10 16:58:36 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int	get_top(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->value);
}

int	get_second(t_stack *stack)
{
	if (!stack || !stack->next)
		return (0);
	return (stack->next->value);
}

int	get_bottom(t_stack *stack)
{
	if (!stack)
		return (0);
	return (get_last_element(stack)->value);
}

int	get_bigger(t_stack *stack)
{
	int	bigger;

	bigger = 0;
	while (stack)
	{
		if (stack->value > bigger)
			bigger = stack->value;
		stack = stack->next;
	}
	return (bigger);
}

t_stack	*get_lowest(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack)
	{
		if (stack->value < tmp->value)
			tmp = stack;
		stack = stack->next;
	}
	return (tmp);
}
