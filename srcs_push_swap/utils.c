/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 23:48:42 by tvader            #+#    #+#             */
/*   Updated: 2021/08/22 14:17:57 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_current(t_s	*a_top, t_s *b_top)
{
	t_s	*cur_a;
	t_s	*cur_b;

	cur_a = a_top;
	cur_b = b_top;
	printf("Current stacks:\na	b\n");
	while (cur_a || cur_b)
	{
		if (cur_a && cur_b)
			printf("%d", cur_a->val);
		else if (cur_a)
			printf("%d\n", cur_a->val);
		if (cur_b)
			printf("	%d\n", cur_b->val);
		if (cur_a)
			cur_a = cur_a->next;
		if (cur_b)
			cur_b = cur_b->next;
	}
	printf("\n");
}

int	is_place(int value, t_s *stack, t_s *cur)
{
	int	next;
	int	curval;

	if (!(cur->next))
	{
		next = stack->val;
		curval = cur->val;
	}
	else
	{
		next = cur->next->val;
		curval = cur->val;
	}
	if (curval == min_value(stack) && next == max_value(stack) && \
	stack_size(stack) > 2)
		return (0);
	if (value < curval && value > next)
		return (1);
	return (0);
}

int	max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

int	ft_abs(int num)
{
	if (num >= 0)
		return (num);
	else
		return (-num);
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
