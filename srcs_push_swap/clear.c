/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:00:58 by tvader            #+#    #+#             */
/*   Updated: 2021/08/21 23:34:44 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	clearing(t_s *a, t_s *b, int ret)
{
	t_s	*next;

	while (b)
	{
		next = b->next;
		free(b);
		b = next;
	}
	while (a)
	{
		next = a->next;
		free(a);
		a = next;
	}
	return (ret);
}

int	is_in_stack(t_s *a, int value)
{
	while (a)
	{
		if (a->val == value)
			return (1);
		a = a->next;
	}
	return (0);
}
