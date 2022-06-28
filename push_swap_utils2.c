/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:29:56 by aespinos          #+#    #+#             */
/*   Updated: 2022/06/28 19:24:34 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*ft_copy_list(t_list *stack)
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

int	ft_isdigit(int a)
{
	int	y;

	y = 1;
	if (a < '0' || a > '9')
		y = 0;
	return (y);
}

void	ft_free(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}
