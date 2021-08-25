/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:42:04 by tvader            #+#    #+#             */
/*   Updated: 2021/08/21 23:34:37 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_s *stack)
{
	int	stacklen;

	stacklen = 0;
	while (stack)
	{
		stack = stack->next;
		stacklen++;
	}
	return (stacklen);
}

int	is_sorted_comb(t_s *stack)
{
	t_s	*cur_elem;
	t_s	*breakpoint_elem;
	int	prev_val;
	int	number;

	breakpoint_elem = NULL;
	number = 0;
	cur_elem = stack;
	prev_val = cur_elem->val;
	while (cur_elem->next)
	{
		if (prev_val > cur_elem->next->val && !breakpoint_elem)
			breakpoint_elem = cur_elem;
		else if (prev_val > cur_elem->next->val)
			return (-1);
		if (!breakpoint_elem)
			number++;
		cur_elem = cur_elem->next;
		prev_val = cur_elem->val;
	}
	if (!breakpoint_elem || stack->val >= cur_elem->val)
		return ((number + 1) * (number + 1 != stack_size(stack)));
	else
		return (-1);
}

int	moves_to_val(int value, t_s *stack)
{
	int	moves;
	t_s	*cur;

	cur = stack;
	moves = 0;
	while (cur->val != value)
	{
		cur = cur->next;
		moves++;
	}
	return (moves);
}

int	where_to_ins(int value, t_s *stack)
{
	int	moves;
	int	size;
	t_s	*cur;

	if (!stack || !(stack->next))
		return (0);
	moves = 1;
	size = stack_size(stack);
	cur = stack;
	if (value > max_value(stack))
		moves = moves_to_val(max_value(stack), stack);
	else if (value < min_value(stack))
		moves = moves_to_val(min_value(stack), stack) + 1;
	else
	{
		while (!is_place(value, stack, cur))
		{
			cur = cur->next;
			moves++;
		}
	}
	return (moves);
}

int	ind_of_min(int	*array, int size)
{
	int	min;
	int	ind;
	int	minind;

	ind = 1;
	minind = 0;
	min = array[0];
	while (ind < size)
	{
		if (array[ind] < min)
		{
			min = array[ind];
			minind = ind;
		}
		ind++;
	}
	return (minind);
}
