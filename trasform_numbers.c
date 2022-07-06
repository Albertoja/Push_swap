/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trasform_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:00:27 by aespinos          #+#    #+#             */
/*   Updated: 2022/07/05 18:18:11 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> 

t_list	*ft_copylst(t_list *stack)
{
	t_list	*temp;
	t_list	*temp2;
	int		nbr;

	temp = ft_lstnew(stack->content);
	stack = stack->next;
	while (stack)
	{
		nbr = stack->content;
		temp2 = ft_lstnew(nbr);
		ft_lstadd_back(&temp, temp2);
		stack = stack->next;
	}
	return (temp);
}

size_t	ft_place(t_list *stack, t_list *content)
{
	int	ret;

	ret = 1;
	while (stack)
	{
		if (stack == content)
			return (ret);
		ret++;
		stack = stack->next;
	}
	return (0);
}

t_list	*ft_trasform_num(t_list *stack)
{
	t_list	*newlist;
	t_list	*head;
	t_list	*min;
	int		nbr;
	int		ret;

	newlist = ft_copylst(stack);
	head = newlist;
	min = next_min(stack, NULL);
	nbr = 1;
	while (min)
	{
		ret = ft_place(stack, min);
		while (--ret)
			newlist = newlist->next;
		newlist->content = nbr++;
		newlist = head;
		min = next_min(stack, min);
	}
	ft_lstclear(&stack);
	return (head);
}