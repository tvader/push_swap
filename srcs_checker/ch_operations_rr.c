/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_operations_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 14:20:04 by tvader            #+#    #+#             */
/*   Updated: 2021/08/22 13:34:48 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	oper_rrr(t_s **a, t_s **b)
{
	if (oper_rra(a))
		return (1);
	if (oper_rrb(b))
		return (2);
	return (0);
}

int	oper_rra(t_s **head)
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
	return (0);
}

int	oper_rrb(t_s **head)
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
	return (0);
}
