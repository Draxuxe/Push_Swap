/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:53:16 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/01 14:52:13 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	swap_quiet(t_stack **swapped)
{
	int		tmp;
	int		temp;
	t_stack	*tempo;

	if (stack_size(swapped) < 2)
		return ;
	tempo = (*swapped);
	tmp = tempo->value;
	temp = tempo->next->value;
	tempo->value = temp;
	tempo->next->value = tmp;
}

void	swap(t_stack **swapped, char c)
{
	int		tmp;
	int		temp;
	t_stack	*tempo;

	if (stack_size(swapped) < 2)
		return ;
	tempo = (*swapped);
	tmp = tempo->value;
	temp = tempo->next->value;
	tempo->value = temp;
	tempo->next->value = tmp;
	ft_putchar('s');
	ft_putchar(c);
	ft_putchar('\n');
}

void	double_swap(t_stack **a, t_stack **b)
{
	swap_quiet(a);
	swap_quiet(b);
	ft_putstr("ss\n");
}
