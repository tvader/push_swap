/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 14:20:04 by tvader            #+#    #+#             */
/*   Updated: 2021/08/21 23:34:41 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	oper_rrr(t_s **a, t_s **b, int *a_moves, int *b_moves)
{
	if (oper_rra(a, 0, a_moves))
		return (1);
	if (oper_rrb(b, 0, b_moves))
		return (2);
	write(1, "rrr\n", 4);
	return (0);
}

int	oper_rra(t_s **head, int self, int *a_moves)
{
	t_s	*buf;
	t_s	*prelast;

	if (!head || !(*head))
		return (-1);
	if (!((*head)->next))
		return (1);
	buf = *head;
	prelast = *head;
	while (prelast->next->next)
		prelast = prelast->next;
	*head = prelast->next;
	prelast->next->next = buf;
	prelast->next = NULL;
	if (self)
		write(1, "rra\n", 4);
	(*a_moves)++;
	return (0);
}

int	oper_rrb(t_s **head, int self, int *b_moves)
{
	t_s	*buf;
	t_s	*prelast;

	if (!head || !(*head))
		return (-1);
	if (!((*head)->next))
		return (1);
	buf = *head;
	prelast = *head;
	while (prelast->next->next)
		prelast = prelast->next;
	*head = prelast->next;
	prelast->next->next = buf;
	prelast->next = NULL;
	if (self)
		write(1, "rrb\n", 4);
	(*b_moves)++;
	return (0);
}
