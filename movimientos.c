/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimientos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:24:51 by aespinos          #+#    #+#             */
/*   Updated: 2022/06/27 19:05:08 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_swap(t_list **stack, char a)
{
	t_list	*temp_01;

	temp_01 = *stack;
	*stack = (*stack)->next->next;
	ft_lstadd_front(stack, ft_lstnew((temp_01)->content));
	temp_01 = temp_01->next;
	ft_lstadd_front(stack, ft_lstnew((temp_01)->content));
	if (a != 'x')
	{
		write(1, "s", 1);
		write(1, &a, 1);
		write(1, "\n", 1);
	}
}

void	ft_push(t_list **desde, t_list **hasta, char a)
{
	ft_lstadd_front(hasta, ft_lstnew((*desde)->content));
	*desde = (*desde)->next;
	if (a != 'x')
	{
		write(1, "p", 1);
		write(1, &a, 1);
		write(1, "\n", 1);
	}
}

void	ft_rotate(t_list **stack, char a)
{
	t_list	*temp_01;

	temp_01 = *stack;
	*stack = (*stack)->next;
	temp_01->next = NULL;
	ft_lstadd_back(stack, temp_01);
	if (a != 'x')
	{
		write(1, "r", 1);
		write(1, &a, 1);
		write(1, "\n", 1);
	}
}

void	ft_revrotate(t_list **stack, char a)
{
	t_list	*temp_01;
	t_list	*temp_02;

	temp_01 = *stack;
	temp_02 = ft_lstlast(*stack);
	while (temp_01->next != temp_02)
		temp_01 = temp_01->next;
	temp_01->next = NULL;
	ft_lstadd_front(stack, temp_02);
	if (a != 'x')
	{
		write(1, "rr", 2);
		write(1, &a, 1);
		write(1, "\n", 1);
	}
}

void	ft_rotate_two(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a, 'x');
	ft_rotate(stack_b, 'x');
	write(1, "rr", 2);
	write(1, "\n", 1);
}
