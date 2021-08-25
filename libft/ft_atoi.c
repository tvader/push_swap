/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:56:21 by tvader            #+#    #+#             */
/*   Updated: 2021/08/20 23:39:45 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(char *str)
{
	int			sign;
	long long	base;

	sign = 1;
	base = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	sign -= 2 * (*str == '-');
	str += (*str == '+' || *str == '-');
	while (*str >= '0' && *str <= '9')
	{
		base = base * 10 + (*str - '0');
		str++;
	}
	return (base * sign);
}
