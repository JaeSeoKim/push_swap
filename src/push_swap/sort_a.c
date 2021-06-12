/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:46:50 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/12 22:05:52 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

static void	call_next_sort(t_push_swap *data, int count[3])
{
	return_stack(data, count[RA_CNT], count[RB_CNT]);
	sort_a(data, count[RA_CNT]);
	sort_b(data, count[RB_CNT]);
	sort_b(data, count[PUSH_CNT] - count[RB_CNT]);
}

static void	move_stack(t_push_swap *data, int pivot[2], int count[3])
{
	if (data->a->content > pivot[BIG])
	{
		++count[RA_CNT];
		operator("ra", data);
	}
	else
	{
		++count[PUSH_CNT];
		operator("pb", data);
		if (data->b->content > pivot[SMALL])
		{
			++count[RB_CNT];
			operator("rb", data);
		}
	}
}

void	sort_a(t_push_swap *data, int size)
{
	int	count[3];
	int	pivot[2];

	if (size <= 1)
		return ;
	ft_memset(&count, 0, sizeof(count));
	get_pivot(pivot, data->a, size);
	while (size-- > 0)
		move_stack(data, pivot, count);
	call_next_sort(data, count);
}
