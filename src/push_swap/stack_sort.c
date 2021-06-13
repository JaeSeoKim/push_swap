/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:25:20 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/13 23:50:28 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort(t_push_swap *data)
{
	int	size;

	size = stack_size(data->a);
	if (size == 5)
		return (sort_five(data));
	if (size == 3)
		return (sort_three(data));
	if (size == 2 && data->a->content > data->a->next->content)
		return (operator("sa", data));
	return (sort_a(data, size));
}
