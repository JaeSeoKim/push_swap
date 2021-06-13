/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:29:01 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/14 00:07:39 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

# define PUSH_CNT	0
# define RA_CNT		1
# define RB_CNT		2

# define DESC		0
# define ASC		1

# define SMALL		0
# define BIG		1

void	stack_sort(t_push_swap *data);
void	get_pivot(int pivot[], t_stack *stack, int n);

void	sort_five(t_push_swap *data);
void	sort_three(t_push_swap *data);
void	sort_a(t_push_swap *data, int size);
void	sort_three_a(t_push_swap *data);
void	sort_b(t_push_swap *data, int size);
void	sort_three_b(t_push_swap *data);
int		check_sort_n(t_stack *stack, int type, int n);
void	return_stack(t_push_swap *data, int ra_cnt, int rb_cnt);

#endif
