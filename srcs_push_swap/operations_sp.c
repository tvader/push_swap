/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_sp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 23:33:35 by tvader            #+#    #+#             */
/*   Updated: 2021/08/21 23:34:40 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	oper_sa(t_s **head, int self)
{
	t_s	*buf;

	if (!head || !(*head))
		return (-1);
	if (!((*head)->next))
		return (-2);
	buf = (*head);
	(*head) = ((*head)->next);
	buf->next = ((*head)->next);
	((*head)->next) = buf;
	if (self)
		write(1, "sa\n", 3);
	return (0);
}

int	oper_sb(t_s **head, int self)
{
	t_s	*buf;

	if (!head || !(*head))
		return (-1);
	if (!((*head)->next))
		return (-2);
	buf = (*head);
	(*head) = ((*head)->next);
	buf->next = ((*head)->next);
	((*head)->next) = buf;
	if (self)
		write(1, "sb\n", 3);
	return (0);
}

int	oper_ss(t_s **a, t_s **b)
{
	oper_sa(a, 0);
	oper_sb(b, 0);
	write(1, "ss\n", 3);
	return (0);
}

int	oper_pa(t_s **head_a, t_s **head_b)
{
	t_s	*buf;

	if (!head_b || !(*head_b))
		return (-1);
	buf = (*head_b);
	(*head_b) = (*head_b)->next;
	buf->next = (*head_a);
	(*head_a) = buf;
	write(1, "pa\n", 3);
	return (0);
}

int	oper_pb(t_s **head_a, t_s **head_b)
{
	t_s	*buf;

	if (!head_a || !(*head_a))
		return (-1);
	buf = (*head_a);
	(*head_a) = (*head_a)->next;
	buf->next = (*head_b);
	(*head_b) = buf;
	write(1, "pb\n", 3);
	return (0);
}
