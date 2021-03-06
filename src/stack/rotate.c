/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:19:53 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/11 18:14:01 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	tmp->prev = stack_last(*stack);
	tmp->prev->next = tmp;
}
