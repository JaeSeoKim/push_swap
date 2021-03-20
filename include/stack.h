/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:10:55 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/20 13:56:03 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

t_d_list	*create_stack_with_arg(int argc, char *argv[]);

#endif
