/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:06:19 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/10 11:53:51 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	clear_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		while (*stack_a)
		{
			tmp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = tmp;
		}
	}
	if (*stack_b)
	{
		tmp = *stack_b;
		if (!tmp)
			return ;
		while (*stack_b)
		{
			tmp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = tmp;
		}
	}
}

int	stack_size(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = (*stack);
	while (temp)
	{
		i ++;
		temp = temp->next;
	}
	return (i);
}

t_stack	*new_elem(t_stack *a, int new)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->value = new;
	newnode->next = a;
	return (newnode);
}

t_stack	*get_element(t_stack *lst, int index)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (i == index)
			return (lst);
		lst = lst->next;
		i++;
	}
	return (NULL);
}

t_stack	*get_last_element(t_stack *lst)
{
	return (get_element(lst, stack_size(&lst) - 1));
}
