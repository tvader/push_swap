/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_edit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:32:12 by tvader            #+#    #+#             */
/*   Updated: 2021/08/25 18:17:54 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	recomb(t_s **stack)
{
	int	moves;

	moves = is_sorted_comb(*stack);
	if (moves < 0)
		return (-1);
	if (moves && moves <= stack_size(*stack) / 2)
		while (moves)
			oper_ra(stack, 1, &moves);
	else if (moves)
		while (moves != stack_size(*stack))
			oper_rra(stack, 1, &moves);
	return (0);
}

int	makemoves(t_s **a_head, t_s **b_head, int a_move, int b_move)
{
	while (a_move < 0 && b_move < 0)
		oper_rrr(a_head, b_head, &a_move, &b_move);
	while (a_move > 0 && b_move > 0)
		oper_rr(a_head, b_head, &a_move, &b_move);
	while (a_move < 0)
		oper_rra(a_head, 1, &a_move);
	while (a_move > 0)
		oper_ra(a_head, 1, &a_move);
	while (b_move < 0)
		oper_rrb(b_head, 1, &b_move);
	while (b_move > 0)
		oper_rb(b_head, 1, &b_move);
	return (0);
}

int	optimizer(int *vars, t_s **a)
{
	float	bot;
	float	top;
	float	size;

	bot = 15.0 / 100;
	top = 85.0 / 100;
	size = 10.0 / 100;
	while ((vars[2] > (int)(vars[5] * bot) \
	&& vars[2] < (int)(vars[5] * top)) \
	&& vars[5] > (int)((vars[5] + vars[6]) * size) \
	&& vars[5] + vars[6] > 50)
	{
		*a = (*a)->next;
		vars[2]++;
	}
	return (0);
}
