/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:53:43 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/03 13:52:17 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	push_quiet(t_stack **original, t_stack **copy)
{
	t_stack	*tmp;
	t_stack	*temp;

	if (!(*original))
		return ;
	tmp = (*original)->next;
	temp = (*original);
	temp->next = (*copy);
	(*copy) = temp;
	(*original) = tmp;
}

void	push(t_stack **original, t_stack **copy, char c)
{
	t_stack	*tmp;
	t_stack	*temp;

	if (!(*original))
		return ;
	tmp = (*original)->next;
	temp = (*original);
	temp->next = (*copy);
	(*copy) = temp;
	(*original) = tmp;
	ft_putchar('p');
	ft_putchar(c);
	ft_putchar('\n');
}
