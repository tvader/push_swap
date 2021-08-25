/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:48:24 by tvader            #+#    #+#             */
/*   Updated: 2021/08/25 19:15:21 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	exec_com(char *com, t_s **a, t_s **b)
{
	if (!ft_strncmp("sa", com, ft_strlen(com)))
		oper_sa(a);
	else if (!ft_strncmp("sb", com, ft_strlen(com)))
		oper_sb(b);
	else if (!ft_strncmp("ss", com, ft_strlen(com)))
		oper_ss(a, b);
	else if (!ft_strncmp("ra", com, ft_strlen(com)))
		oper_ra(a);
	else if (!ft_strncmp("rb", com, ft_strlen(com)))
		oper_rb(b);
	else if (!ft_strncmp("rr", com, ft_strlen(com)))
		oper_rr(a, b);
	else if (!ft_strncmp("rra", com, ft_strlen(com)))
		oper_rra(a);
	else if (!ft_strncmp("rrb", com, ft_strlen(com)))
		oper_rrb(b);
	else if (!ft_strncmp("rrr", com, ft_strlen(com)))
		oper_rrr(a, b);
	else if (!ft_strncmp("pa", com, ft_strlen(com)))
		oper_pa(a, b);
	else if (!ft_strncmp("pb", com, ft_strlen(com)))
		oper_pb(a, b);
	else
		clearing(*a, *b, 1);
}

void	execute(char *buf, t_s **a, t_s **b)
{
	char	com[5];
	int		i;
	int		j;

	j = 0;
	while (buf[j])
	{
		i = 0;
		while (i < 3 && buf[j] && (buf[j] != '\n' && buf[j] != ' '))
		{
			com[i] = buf[j];
			i++;
			j++;
		}
		com[i] = 0;
		if (buf[j++] || ft_strlen(buf) < BS - 1)
		{
			exec_com(com, a, b);
			ft_bzero((void *)com, 5);
		}
	}
	if (com[0] && (buf[BS - 2] == ' ' || buf[BS - 2] == '\n'))
		com[ft_strlen(com)] = buf[BS - 2];
	ft_strlcpy((char *)buf, com, BS);
	ft_bzero((void *)(buf + ft_strlen(com)), BS - 1 - ft_strlen(com));
}

int	main(int argc, char **argv)
{
	t_s		*a;
	t_s		*b;
	char	buf[BS];
	int		c_read;

	check_args(argc, argv);
	a = read_stack(argc, argv);
	b = NULL;
	ft_bzero((void *)buf, BS);
	while (1)
	{
		c_read = read(0, buf + ft_strlen(buf), BS - 1 - ft_strlen(buf));
		if (!c_read)
			break ;
		execute((char *)buf, &a, &b);
	}
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clearing(a, b, 0);
	return (0);
}
