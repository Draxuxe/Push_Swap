/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:49:33 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/01 14:51:39 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	rotate_quiet(t_stack **rotated)
{
	t_stack	*tmp;
	int		temp;

	if (stack_size(rotated) < 2)
		return ;
	temp = (*rotated)->value;
	tmp = (*rotated);
	while (tmp->next)
	{
		tmp->value = tmp->next->value;
		tmp = tmp->next;
	}
	tmp->value = temp;
}

void	rotate(t_stack **rotated, char c)
{
	t_stack	*tmp;
	int		temp;

	if (stack_size(rotated) < 2)
		return ;
	temp = (*rotated)->value;
	tmp = (*rotated);
	while (tmp->next)
	{
		tmp->value = tmp->next->value;
		tmp = tmp->next;
	}
	tmp->value = temp;
	ft_putchar('r');
	ft_putchar(c);
	ft_putchar('\n');
}

void	double_rotate(t_stack **a, t_stack **b)
{
	rotate_quiet(a);
	rotate_quiet(b);
	ft_putstr("rr\n");
}
