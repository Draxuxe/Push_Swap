/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:23:38 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/17 12:16:09 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	print_list(t_stack *x)
{
	while (x)
	{
		printf("%d\n", x->value);
		x = x->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit (EXIT_FAILURE);
	}
	b = NULL;
	parser(&a, av, ac);
	sort(&a, &b);
	clear_stacks(&a, &b);
	return (0);
}
