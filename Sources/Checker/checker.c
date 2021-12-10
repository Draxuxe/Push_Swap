/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:28:44 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/10 10:21:11 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	dispatch_command_1(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(cmd, "rr\n"))
	{
		rotate_quiet(stack_a);
		rotate_quiet(stack_b);
	}
	else if (ft_strcmp(cmd, "rra\n"))
		reverse_rotate_quiet(stack_a);
	else if (ft_strcmp(cmd, "rrb\n"))
		reverse_rotate_quiet(stack_b);
	else if (ft_strcmp(cmd, "rrr\n"))
	{
		reverse_rotate_quiet(stack_a);
		reverse_rotate_quiet(stack_b);
	}
	else
		exit_error();
}

void	dispatch_command(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(cmd, "sa\n"))
		swap_quiet(stack_a);
	else if (ft_strcmp(cmd, "sb\n"))
		swap_quiet(stack_b);
	else if (ft_strcmp(cmd, "ss\n"))
	{
		swap_quiet(stack_a);
		swap_quiet(stack_b);
	}
	else if (ft_strcmp(cmd, "pa\n"))
		push_quiet(stack_b, stack_a);
	else if (ft_strcmp(cmd, "pb\n"))
		push_quiet(stack_a, stack_b);
	else if (ft_strcmp(cmd, "ra\n"))
		rotate_quiet(stack_a);
	else if (ft_strcmp(cmd, "rb\n"))
		rotate_quiet(stack_b);
	else
		dispatch_command_1(cmd, stack_a, stack_b);
}

void	handle_standard_input(t_stack *stack_a, t_stack *stack_b)
{
	char		*line;

	line = get_next_line(0);
	while (line)
	{
		dispatch_command(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (!stack_b && stack_a && is_sorted(stack_a))
		printf("OK\n");
	else
		printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	parser(&stack_a, argv, argc);
	handle_standard_input(stack_a, stack_b);
	clear_stacks(&stack_a, &stack_b);
	return (0);
}
