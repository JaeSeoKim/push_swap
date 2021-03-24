/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:54:40 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/22 21:35:19 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	check_stack_sorted(t_d_list *stack_a, t_d_list *stack_b)
{
	int	n;

	if (stack_b != NULL || stack_a == NULL)
		return (0);
	n = (int)stack_a->content;
	while (stack_a)
	{
		if (n > (int)stack_a->content)
			return (0);
		n = (int)stack_a->content;
		stack_a = stack_a->next;
	}
	return (1);
}
