/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:03:44 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/11 18:17:01 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack)
{
	int	content_tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	content_tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = content_tmp;
}
