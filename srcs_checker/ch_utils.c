/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 23:48:42 by tvader            #+#    #+#             */
/*   Updated: 2021/08/22 18:33:54 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
