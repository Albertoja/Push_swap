/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:23:18 by aespinos          #+#    #+#             */
/*   Updated: 2022/07/04 17:28:01 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void leaks(void)
// {
// 	system("leaks push_swap");
// }

int	main(int argc, char **argv)
{
	//atexit(leaks);
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		exit (0);
	ft_create_lst(&stack_a, argc, argv);
	if (ft_check_list(stack_a) == 0)
	{
		ft_lstclear(&stack_a);
		exit (0);
	}
	stack_a = ft_trasform_num(stack_a);
	if (ft_lstsize(stack_a) < 6)
		ft_sort_undo_five(stack_a, stack_b);
	else if (ft_lstsize(stack_a) >= 6)
		ft_order(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	exit (0);
}
