/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:41:45 by aespinos          #+#    #+#             */
/*   Updated: 2022/06/23 18:02:20 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> 

t_list	*ft_min(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*ft_max(t_list *stack)
{
	t_list	*max;

	max = stack;
	while (stack)
	{
		if (stack->content > max->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_list	*next_min(t_list *stack, t_list *pre_min)
{
	t_list	*min;

	min = ft_max(stack);
	if (!pre_min)
		return (ft_min(stack));
	else if (pre_min->content == min->content)
		return (NULL);
	while (stack)
	{
		if (stack->content < min->content && pre_min->content < stack->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	ft_search_less(t_list *stack, int num)
{
	int	cont_01;
	int	cont_02;
	int	cont_aux;

	cont_01 = 0;
	cont_02 = 0;
	cont_aux = 0;
	while (stack->content < num && cont_01++ >= 0)
		ft_rotate(&stack, 'x');
	while (cont_aux++ < cont_01)
		ft_revrotate(&stack, 'x');
	cont_aux = 0;
	while (stack->content < num && cont_02++ >= 0)
		ft_revrotate(&stack, 'x');
	while (cont_aux++ < cont_02)
		ft_rotate(&stack, 'x');
	if (cont_01 > cont_02)
		return (1);
	else
		return (0);
}
