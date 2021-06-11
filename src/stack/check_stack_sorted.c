/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:54:40 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/11 18:13:45 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	check_stack_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int	n;

	if (stack_b != NULL || stack_a == NULL)
		return (0);
	n = stack_a->content;
	while (stack_a)
	{
		if (n > stack_a->content)
			return (0);
		n = stack_a->content;
		stack_a = stack_a->next;
	}
	return (1);
}
