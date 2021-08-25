/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:00:58 by tvader            #+#    #+#             */
/*   Updated: 2021/08/25 12:35:09 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	clearing(t_s *a, t_s *b, int ret)
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
	if (ret)
		error();
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
