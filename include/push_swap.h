/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:29:01 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/12 21:57:19 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

# define VISUAL_SPEED	10000

# define PUSH_CNT	0
# define RA_CNT		1
# define RB_CNT		2

# define SMALL		0
# define BIG		1

typedef struct s_push_swap
{
	t_stack		*a;
	t_stack		*b;
	int			visualizer;
}				t_push_swap;

void	stack_sort(t_push_swap *data);
void	get_pivot(int pivot[], t_stack *stack, int n);
void	operator(char *op, t_push_swap *data);

void	sort_a(t_push_swap *data, int size);
void	sort_b(t_push_swap *data, int size);
void	return_stack(t_push_swap *data, int ra_cnt, int rb_cnt);

#endif
