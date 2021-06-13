/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:41:13 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/13 19:35:31 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort_n(t_stack *stack, int type, int n)
{
	int		check;

	if (stack == NULL)
		return (1);
	check = stack->content;
	stack = stack->next;
	while (--n > 0 && stack)
	{
		if (type == DESC)
		{
			if (stack->content > check)
				return (0);
			check = stack->content;
		}
		else if (type == ASC)
		{
			if (stack->content < check)
				return (0);
			check = stack->content;
		}
		stack = stack->next;
	}
	return (1);
}
