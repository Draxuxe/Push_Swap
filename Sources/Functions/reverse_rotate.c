/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:47:23 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/03 10:21:12 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	reverse_rotate_quiet(t_stack **rrotated)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*previous;

	if (stack_size(rrotated) < 2)
		return ;
	tmp = (*rrotated);
	last = tmp;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	last->next = tmp;
	previous->next = NULL;
	*rrotated = last;
}

void	reverse_rotate(t_stack **rrotated, char c)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*previous;

	if (stack_size(rrotated) < 2)
		return ;
	tmp = (*rrotated);
	last = tmp;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	last->next = tmp;
	previous->next = NULL;
	*rrotated = last;
	ft_putstr("rr");
	ft_putchar(c);
	ft_putchar('\n');
}

void	double_reverse_rotate(t_stack **a, t_stack **b)
{
	reverse_rotate_quiet(a);
	reverse_rotate_quiet(b);
	ft_putstr("rrr\n");
}
