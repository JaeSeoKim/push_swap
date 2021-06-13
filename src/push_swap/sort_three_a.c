/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:38:59 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/13 22:43:46 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	type_a(t_push_swap *data)
{
	if (data->a->content < data->a->next->next->content)
		return (operator("sa", data));
	operator("sa", data);
	operator("ra", data);
	operator("sa", data);
	operator("rra", data);
}

static void	type_b(t_push_swap *data)
{
	operator("sa", data);
	operator("ra", data);
	operator("sa", data);
	operator("rra", data);
	operator("sa", data);
}

static void	type_c(t_push_swap *data)
{
	operator("ra", data);
	operator("sa", data);
	operator("rra", data);
	operator("sa", data);
}

static void	type_d(t_push_swap *data)
{
	operator("ra", data);
	operator("sa", data);
	operator("rra", data);
}

void	sort_three_a(t_push_swap *data)
{
	if (check_sort_n(data->a, ASC, 3))
		return ;
	if (data->a->content > data->a->next->content && \
		data->a->next->content < data->a->next->next->content)
		return (type_a(data));
	if (data->a->content > data->a->next->content && \
		data->a->next->content > data->a->next->next->content)
		return (type_b(data));
	if (data->a->content < data->a->next->content && \
		data->a->next->content > data->a->next->next->content)
	{
		if (data->a->content > data->a->next->next->content)
			return (type_c(data));
		return (type_d(data));
	}
}
