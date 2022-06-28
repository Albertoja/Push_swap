/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:11:45 by aespinos          #+#    #+#             */
/*   Updated: 2022/06/28 19:19:35 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_elcomeback(t_list **stack_a, t_list **stack_b)
{
	int	boton;

	boton = 0;
	while (*stack_b)
	{
		if ((*stack_b)-> content == (ft_max(*stack_b)-> content) - 1)
		{
			ft_push(stack_b, stack_a, 'a');
			boton = 1;
		}
		if ((*stack_b)-> content != ft_max(*stack_b)-> content)
		{
			if (ft_search_less(*stack_b, ft_max(*stack_b)-> content) == 0)
				ft_rotate(stack_b, 'b');
			else if (ft_search_less(*stack_b, ft_max(*stack_b)-> content) == 1)
				ft_revrotate(stack_b, 'b');
		}
		if ((*stack_b)-> content == ft_max(*stack_b)-> content)
		{
			ft_push(stack_b, stack_a, 'a');
			if (boton == 1)
				ft_swap(stack_a, 'a');
			boton = 0;
		}
	}
}

void	ft_search_stack(t_list **stack_a, t_list **stack_b
							, int stack_num, int size)
{
	int	stack_aux;

	stack_aux = stack_num / 2;
	while (ft_lstsize(*stack_a) > 3 && stack_num < size
		&& check_list_order(*stack_a) == 1)
	{
		while ((*stack_a)->content > stack_num
			&& ft_lstsize(*stack_b) <= stack_num)
			ft_rotate(stack_a, 'a');
		if ((*stack_a)->content <= stack_num)
		{
			ft_push(stack_a, stack_b, 'b');
			if ((*stack_b)->content <= (stack_num - stack_aux))
			{
				if ((*stack_a)->content > stack_num
					&& ft_lstsize(*stack_b) <= stack_num)
					ft_rotate_two(stack_a, stack_b);
				else
					ft_rotate(stack_b, 'b');
			}		
		}
		if (ft_lstsize(*stack_b) == stack_num)
			stack_num = stack_num + (stack_aux * 2);
	}
}

void	ft_order(t_list **stack_a, t_list **stack_b)
{
	int	stack_num;
	int	size;

	size = ft_lstsize(*stack_a);
	if (ft_lstsize(*stack_a) < 300)
		stack_num = 30;
	else
		stack_num = 60;
	ft_search_stack(stack_a, stack_b, stack_num, size);
	while (ft_lstsize(*stack_a) > 3 && check_list_order(*stack_a) == 1)
	{
		if ((*stack_a)-> content == ft_min(*stack_a)-> content)
			ft_push(stack_a, stack_b, 'b');
		else
			ft_rotate(stack_a, 'a');
	}
	if (ft_lstsize(*stack_a) == 3)
		ft_size_3(stack_a);
	ft_elcomeback(stack_a, stack_b);
	exit (0);
}
