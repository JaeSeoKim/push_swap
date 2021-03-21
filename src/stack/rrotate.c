/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:19:53 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/21 17:46:29 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rrotate(t_d_list **stack)
{
	t_d_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = ft_d_lstlast(*stack);
	(*stack)->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = (*stack);
	*stack = last;
}
