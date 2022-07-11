/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:23:18 by aespinos          #+#    #+#             */
/*   Updated: 2022/07/11 18:58:21 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	ft_create_lst(&stack_a, argc, argv);
	if (ft_check_list(stack_a) == 0)
	{
		ft_lstclear(&stack_a);
		exit(0);
	}
	stack_a = ft_trasform_num(stack_a);
	if (ft_lstsize(stack_a) < 6)
		ft_sort_undo_five(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) >= 6)
		ft_order(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	exit(0);
}
