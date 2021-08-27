/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:48:24 by tvader            #+#    #+#             */
/*   Updated: 2021/08/27 12:27:04 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	exec_com(char *com, t_s **a, t_s **b)
{
	if (!ft_strncmp("sa\n", com, ft_strlen(com)))
		oper_sa(a);
	else if (!ft_strncmp("sb\n", com, ft_strlen(com)))
		oper_sb(b);
	else if (!ft_strncmp("ss\n", com, ft_strlen(com)))
		oper_ss(a, b);
	else if (!ft_strncmp("ra\n", com, ft_strlen(com)))
		oper_ra(a);
	else if (!ft_strncmp("rb\n", com, ft_strlen(com)))
		oper_rb(b);
	else if (!ft_strncmp("rr\n", com, ft_strlen(com)))
		oper_rr(a, b);
	else if (!ft_strncmp("rra\n", com, ft_strlen(com)))
		oper_rra(a);
	else if (!ft_strncmp("rrb\n", com, ft_strlen(com)))
		oper_rrb(b);
	else if (!ft_strncmp("rrr\n", com, ft_strlen(com)))
		oper_rrr(a, b);
	else if (!ft_strncmp("pa\n", com, ft_strlen(com)))
		oper_pa(a, b);
	else if (!ft_strncmp("pb\n", com, ft_strlen(com)))
		oper_pb(a, b);
	else
		clearing(*a, *b, 1);
}

int	printres(t_s *a, t_s *b)
{
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clearing(a, b, 0);
	exit (0);
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
	c_read = 1;
	while (1)
	{
		ft_bzero((void *)buf, BS);
		while (ft_strlen(buf) < 4 && buf[ft_strlen(buf) - 1] != '\n' && c_read)
			c_read = read(0, buf + ft_strlen(buf), 1);
		if (!c_read && !buf[0])
			break ;
		exec_com((char *)buf, &a, &b);
	}
	printres(a, b);
	return (0);
}
