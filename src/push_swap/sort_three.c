/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 23:25:47 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/13 23:59:45 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_a(t_push_swap *data)
{
	operator("ra", data);
	operator("sa", data);
}

static void	case_b(t_push_swap *data)
{
	operator("sa", data);
	operator("ra", data);
}

void	sort_three(t_push_swap *data)
{
	if (check_sort_n(data->a, ASC, 3))
		return ;
	if (data->a->content < data->a->next->content && \
		data->a->next->content > data->a->next->next->content && \
		data->a->content > data->a->next->next->content)
		return (operator("rra", data));
	if (data->a->content > data->a->next->content && \
		data->a->next->content < data->a->next->next->content && \
		data->a->content < data->a->next->next->content)
		return (operator("sa", data));
	if (data->a->content > data->a->next->content && \
		data->a->next->content < data->a->next->next->content && \
		data->a->content > data->a->next->next->content)
		return (operator("ra", data));
	if (data->a->content > data->a->next->content && \
		data->a->next->content > data->a->next->next->content)
		return (case_a(data));
	if (data->a->content < data->a->next->content && \
		data->a->next->content > data->a->next->next->content && \
		data->a->content < data->a->next->next->content)
		return (case_b(data));
}
