/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 23:33:35 by tvader            #+#    #+#             */
/*   Updated: 2021/08/21 23:34:42 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	oper_ra(t_s **head, int self, int *a_moves)
{
	t_s	*buf;
	t_s	*last;

	if (!head || !(*head))
		return (-1);
	if (!((*head)->next))
		return (1);
	buf = *head;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = buf;
	*head = buf->next;
	buf->next = NULL;
	if (self)
		write(1, "ra\n", 3);
	(*a_moves)--;
	return (0);
}

int	oper_rb(t_s **head, int self, int *b_moves)
{
	t_s	*buf;
	t_s	*last;

	if (!head || !(*head))
		return (-1);
	if (!((*head)->next))
		return (1);
	buf = *head;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = buf;
	*head = buf->next;
	buf->next = NULL;
	if (self)
		write(1, "rb\n", 3);
	(*b_moves)--;
	return (0);
}

int	oper_rr(t_s **a, t_s **b, int *a_moves, int *b_moves)
{
	if (oper_ra(a, 0, a_moves))
		return (1);
	if (oper_rb(b, 0, b_moves))
		return (2);
	write(1, "rr\n", 3);
	return (0);
}
