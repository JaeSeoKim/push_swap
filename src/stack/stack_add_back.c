/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:23:56 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/11 18:14:17 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_add_back(t_stack **lst, t_stack *new_list)
{
	t_stack	*last;

	if (*lst == NULL)
	{
		*lst = new_list;
		return ;
	}
	last = stack_last(*lst);
	last->next = new_list;
	new_list->prev = last;
}
