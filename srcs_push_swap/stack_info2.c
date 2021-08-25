/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:42:04 by tvader            #+#    #+#             */
/*   Updated: 2021/08/22 18:46:40 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	calc_steps(int *m_a, int *m_b, int size_a, int size_b)
{
	int	*roll;
	int	best_var;
	int	res;

	roll = malloc(sizeof(int) * 4);
	roll[0] = max(*m_a, *m_b);
	roll[1] = *m_a + size_b - *m_b;
	roll[2] = *m_b + size_a - *m_a;
	roll[3] = max(size_a - *m_a, size_b - *m_b);
	best_var = ind_of_min(roll, 4);
	if (best_var == 1)
		*m_b = *m_b - size_b;
	else if (best_var == 2)
		*m_a = *m_a - size_a;
	else if (best_var == 3)
	{
		*m_b = *m_b - size_b;
		*m_a = *m_a - size_a;
	}
	res = roll[best_var];
	free(roll);
	return (res);
}
