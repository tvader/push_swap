/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:52:19 by tvader            #+#    #+#             */
/*   Updated: 2021/08/25 19:15:51 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_s	*creation(int new_value)
{
	t_s	*new_elem;

	new_elem = (t_s *)malloc(sizeof(t_s));
	if (!new_elem)
		return (NULL);
	new_elem->val = new_value;
	new_elem->next = NULL;
	return (new_elem);
}

int	push_back(int new_value, t_s **stack_head)
{
	t_s	*cur;

	if (!(*stack_head))
	{
		(*stack_head) = creation(new_value);
		if (!(*stack_head))
			return (-1);
		return (0);
	}
	cur = *stack_head;
	while (cur->next)
		cur = cur->next;
	cur->next = creation(new_value);
	if (!(cur->next))
		return (-1);
	return (0);
}

long long	*next_num(char **args)
{
	long long	*num;
	int			numlen;

	numlen = 0;
	num = (long long *) ft_calloc(sizeof(long long), 1);
	while ((!(ft_isdigit(**args) || **args == '-')) && **args)
		(*args)++;
	while ((*args)[numlen] && (*args)[numlen] != ' ')
		numlen++;
	if (numlen > 13)
	{
		free(num);
		return (NULL);
	}
	(*num) = ft_atoi(*args);
	while (ft_isdigit(**args) && **args)
		(*args)++;
	while (((ft_isdigit(**args) || **args == '-')) && **args)
		(*args)++;
	return (num);
}

t_s	*read_stack(int cnt, char **args)
{
	t_s			*a;
	long long	*num;

	a = NULL;
	args++;
	while (cnt > 1)
	{
		while (**args)
		{
			num = next_num(args);
			if (!num || (*num) > INT_MAX || (*num) < INT_MIN || \
			is_in_stack(a, (int)(*num)) || push_back((int)(*num), &a))
			{
				clearing(a, NULL, 1);
				error();
			}
			free(num);
		}
		args++;
		cnt--;
	}
	return (a);
}

int	check_args(int cnt, char **args)
{
	int	i;
	int	j;

	if (cnt <= 1)
		error();
	i = 1;
	j = 0;
	while (i < cnt)
	{
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]) && args[i][j] != ' ' \
			&& !(args[i][j] == '-' && (j == 0 || args[i][j - 1] == ' ')))
				error();
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
