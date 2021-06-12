/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:28:43 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/12 21:55:19 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operator(char *op, t_push_swap *data)
{
	if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "rr"))
		rotate(&data->a);
	if (!ft_strcmp(op, "rb") || !ft_strcmp(op, "rr"))
		rotate(&data->b);
	if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrr"))
		rrotate(&data->a);
	if (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr"))
		rrotate(&data->b);
	if (!ft_strcmp(op, "pa"))
		push(&data->b, &data->a);
	if (!ft_strcmp(op, "pb"))
		push(&data->a, &data->b);
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss"))
		swap(data->a);
	if (!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss"))
		swap(data->b);
	if (data->visualizer)
	{
		system("clear");
		print_stacks(data->a, data->b);
		usleep(VISUAL_SPEED);
	}
	ft_putendl_fd(op, 1);
}
