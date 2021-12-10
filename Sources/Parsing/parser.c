/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:27:29 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/08 15:00:47 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int	count_args(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i ++;
	return (i);
}

void	check_errors(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*temp;
	int		i;

	tmp = a;
	while (tmp)
	{
		i = -1;
		temp = tmp;
		while (temp)
		{
			if (temp->value == tmp->value)
			{
				i ++;
				if (i == 1)
				{
					printf("Error\n");
					exit (EXIT_FAILURE);
				}
			}
		temp = temp->next;
		}
	tmp = tmp->next;
	}
}

void	parser(t_stack **a, char **av, int ac)
{
	int		i;
	int		j;
	int		value;
	char	**param;

	i = ac - 1;
	while (i > 0)
	{
		param = ft_split(av[i], ' ');
		j = count_args(param) - 1;
		while (j > -1)
		{
			value = ft_atoi(param[j]);
			*a = new_elem(*a, value);
			free(param[j]);
			i --;
			j --;
		}
		free(param);
	}
	check_errors(*a);
}
