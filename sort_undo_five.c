/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_undo_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:30:04 by aespinos          #+#    #+#             */
/*   Updated: 2022/06/23 16:59:50 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_size_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a < b && b < c && a < c)
		return ;
	if (b > a && a < c && a < b)
	{
		ft_swap(stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else if (a > b && a < c && b < c)
		ft_swap(stack_a, 'a');
	else if (a < b && a > c && b > c)
		ft_revrotate(stack_a, 'a');
	else if (a > b && a > c && b < c)
		ft_rotate(stack_a, 'a');
	else if (a > b && a > c && b > c)
	{
		ft_swap(stack_a, 'a');
		ft_revrotate(stack_a, 'a');
	}
}

void	ft_size_3_pre(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a < b && b < c && a < c)
		return ;
	if (b > a && a < c && a < b)
	{
		ft_swap(stack_a, 'x');
		ft_rotate(stack_a, 'x');
	}
	else if (a > b && a < c && b < c)
		ft_swap(stack_a, 'x');
	else if (a < b && a > c && b > c)
		ft_revrotate(stack_a, 'x');
	else if (a > b && a > c && b < c)
		ft_rotate(stack_a, 'x');
	else if (a > b && a > c && b > c)
	{
		ft_swap(stack_a, 'x');
		ft_revrotate(stack_a, 'x');
	}
}

void	ft_size_4(t_list **stack_a, t_list **stack_b)
{
	while (ft_min(*stack_a) != (*stack_a))
	{
		if (ft_min(*stack_a) == (*stack_a)->next
			&& ft_max(*stack_a) != (*stack_a))
			ft_swap(stack_a, 'a');
		else if (ft_min(*stack_a) == (*stack_a)->next->next->next)
			ft_revrotate(stack_a, 'a');
		else
			ft_rotate(stack_a, 'a');
	}
	if (check_list_order(*stack_a) != 0)
	{
		ft_push(stack_a, stack_b, 'b');
		ft_size_3(stack_a);
		ft_push(stack_b, stack_a, 'a');
	}
}

void	ft_size_5(t_list **stack_a, t_list **stack_b)
{
	while (ft_min(*stack_a) != (*stack_a))
	{
		if (ft_min(*stack_a) <= (*stack_a)->next->next)
			ft_rotate(stack_a, 'a');
		else
			ft_revrotate(stack_a, 'a');
	}
	if (check_list_order(*stack_a) != 0)
	{
		ft_push(stack_a, stack_b, 'b');
		ft_size_4(stack_a, stack_b);
		ft_push(stack_b, stack_a, 'a');
		if (ft_max(*stack_a) == *stack_a)
			ft_rotate(stack_a, 'a');
	}
}

void	ft_sort_undo_five(t_list *stack_a, t_list *stack_b)
{
	stack_b = 0;
	if (ft_lstsize(stack_a) == 2)
	{
		if ((stack_a->content) > (stack_a->next->content))
			ft_swap(&stack_a, 'a');
	}
	else if (ft_lstsize(stack_a) == 3)
		ft_size_3(&stack_a);
	else if (ft_lstsize(stack_a) == 4)
		ft_size_4(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) == 5)
		ft_size_5(&stack_a, &stack_b);
}
