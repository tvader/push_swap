/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:04:49 by tvader            #+#    #+#             */
/*   Updated: 2021/08/31 11:08:14 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// In vars[] : 0,1 - moves a,b, 2 - iterations, 3 - current steps,
// 4 - potential steps, 5 - size of a, 6 - size of b
int	step_selection(t_s *a, t_s *b, int *cur_a, int *cur_b)
{
	int	*vars;

	vars = ft_calloc(7, sizeof(int));
	vars[5] = stack_size(a);
	vars[6] = stack_size(b);
	while (a)
	{
		optimizer(vars, &a);
		vars[0] = vars[2];
		vars[1] = where_to_ins(a->val, b);
		vars[4] = calc_steps(&vars[0], &vars[1], vars[5], vars[6]);
		if (vars[2] == 0 || vars[4] < vars[3])
		{
			vars[3] = vars[4];
			*cur_a = vars[0];
			*cur_b = vars[1];
		}
		a = a->next;
		vars[2]++;
	}
	free(vars);
	return (0);
}

int	main_sort(t_s **a, t_s **b)
{
	int	cnt;
	int	moves_a;
	int	moves_b;

	moves_a = 0;
	moves_b = 0;
	cnt = 0;
	oper_pb(a, b);
	oper_pb(a, b);
	while (*a)
	{
		step_selection(*a, *b, &moves_a, &moves_b);
		makemoves(a, b, moves_a, moves_b);
		oper_pb(a, b);
		cnt++;
	}
	while (*b)
		oper_pa(a, b);
	recomb(a);
	return (0);
}

int	main(int cnt, char **args)
{
	t_s	*a;
	t_s	*b;

	b = NULL;
	check_args(cnt, args);
	a = read_stack(cnt, args);
	if (recomb(&a))
	{
		if (stack_size(a) <= 6)
			little_sort(&a, &b);
		else
			main_sort(&a, &b);
	}
	return (clearing(a, b, 0));
}
