/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:21:57 by aespinos          #+#    #+#             */
/*   Updated: 2022/06/27 20:31:49 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_create_lst(t_list **stack_a, int argc, char **argv)
{
	int		cont;
	char	*str;
	char	**mat;

	cont = 0;
	str = NULL;
	while (++cont < argc)
	{
		if (!str)
			str = ft_strdup(argv[cont]);
		else
		{
			str = ft_strjoin(str, " ");
			str = ft_strjoin(str, argv[cont]);
		}
	}
	mat = ft_split(str, ' ');
	free(str);
	ft_check_letters(mat);
	cont = -1;
	while (mat[++cont])
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi_check(mat[cont], mat)));
	}
	ft_free(mat);
}
