/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_operations_sp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 23:33:35 by tvader            #+#    #+#             */
/*   Updated: 2021/08/22 13:35:35 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	oper_sa(t_s **head)
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
	return (0);
}

int	oper_sb(t_s **head)
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
	return (0);
}

int	oper_ss(t_s **a, t_s **b)
{
	oper_sa(a);
	oper_sb(b);
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
	return (0);
}
