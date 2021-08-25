/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_operations_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 23:33:35 by tvader            #+#    #+#             */
/*   Updated: 2021/08/22 13:53:56 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	oper_ra(t_s **head)
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
	return (0);
}

int	oper_rb(t_s **head)
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
	return (0);
}

int	oper_rr(t_s **a, t_s **b)
{
	if (oper_ra(a))
		return (1);
	if (oper_rb(b))
		return (2);
	return (0);
}
