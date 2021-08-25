/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_stack_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:42:04 by tvader            #+#    #+#             */
/*   Updated: 2021/08/22 18:47:08 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	is_sorted(t_s *stack)
{
	t_s	*cur_elem;
	int	prev_value;

	if (!stack)
		return (-1);
	cur_elem = stack->next;
	prev_value = stack->val;
	while (cur_elem && prev_value <= cur_elem->val)
	{
		prev_value = cur_elem->val;
		cur_elem = cur_elem->next;
	}
	if (cur_elem)
		return (0);
	return (1);
}

int	min_value(t_s *stack)
{
	int	min;

	if (!stack)
		return (-666);
	min = stack->val;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->val < min)
			min = stack->val;
	}
	return (min);
}

int	max_value(t_s *stack)
{
	int	max;

	if (!stack)
		return (-666);
	max = stack->val;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->val > max)
			max = stack->val;
	}
	return (max);
}
