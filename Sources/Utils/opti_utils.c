/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:30:40 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/10 17:46:51 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	move_opti_b(t_stack **b, t_stack **a, char func, char stack)
{
	if (ft_strccmp(func, 's'))
	{
		if (!is_sorted(*a) && (get_top(*b) < get_second(*b)))
			double_swap(a, b);
		else
			swap(b, stack);
	}
	if (ft_strccmp(func, 'r'))
	{
		if ((get_top(*a) > get_second(*a))
			&& (get_top(*b) < get_second(*b)))
			double_rotate(b, a);
		else
			rotate(b, stack);
	}
}

void	move_opti_rrb(t_stack **b, t_stack **a, char *func, char stack)
{
	if (ft_strcmp(func, "rr"))
	{
		if (!is_sorted(*a) && (get_top(*b) < get_bottom(*b))
			&& (get_top(*a) < get_bottom(*a)))
			double_reverse_rotate(a, b);
		else
			reverse_rotate(b, stack);
	}
}

void	move_opti_rra(t_stack **b, t_stack **a, char *func, char stack)
{
	if (ft_strcmp(func, "rr"))
	{
		if (!is_sorted(*a) && (get_top(*b) < get_bottom(*b))
			&& (get_top(*a) < get_bottom(*a)))
			double_reverse_rotate(a, b);
		else
			reverse_rotate(a, stack);
	}
}

void	move_opti_a(t_stack **a, t_stack **b, char func, char stack)
{
	if (ft_strccmp(func, 's'))
	{
		if (!is_sorted(*a) && (get_top(*b) < get_second(*b)))
			double_swap(a, b);
		else
			swap(a, stack);
	}
	if (ft_strccmp(func, 'r'))
	{
		if ((get_top(*a) > get_second(*a))
			&& (get_top(*b) < get_second(*b)))
			double_rotate(b, a);
		else
			rotate(a, stack);
	}
}

void	move_opti(t_stack **a, int i)
{
	int		lowest;
	t_stack	*tmp;
	int		index;

	(void)i;
	tmp = (*a);
	index = 0;
	lowest = get_lowest(*a)->value;
	while (tmp)
	{
		if (tmp->value == lowest)
			break ;
		index ++;
		tmp = tmp->next;
	}
	get_lowest_top(a, index, i);
}
