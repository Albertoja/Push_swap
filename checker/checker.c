/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:06:11 by aespinos          #+#    #+#             */
/*   Updated: 2022/07/06 19:46:40 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

int	ft_swap_comp(t_list **check_a, t_list **check_b, char *str, int len)
{
	if (!ft_strncmp(str, "sa\n", len))
		ft_swap(check_a, 'x');
	else if (!ft_strncmp(str, "sb\n", len))
		ft_swap(check_b, 'x');
	else if (!ft_strncmp(str, "ss\n", len))
	{
		ft_swap(check_a, 'x');
		ft_swap(check_b, 'x');
	}
	else
		return (1);
	return (0);
}

int	ft_push_comp(t_list **check_a, t_list **check_b, char *str, int len)
{
	if (!ft_strncmp(str, "pa\n", len))
		ft_push(check_b, check_a, 'x');
	else if (!ft_strncmp(str, "pb\n", len))
		ft_push(check_a, check_b, 'x');
	else
		return (1);
	return (0);
}

int	ft_rot_comp(t_list **check_a, t_list **check_b, char *str, int len)
{
	if (!ft_strncmp(str, "ra\n", len))
		ft_rotate(check_a, 'x');
	else if (!ft_strncmp(str, "rb\n", len))
		ft_rotate(check_b, 'x');
	else if (!ft_strncmp(str, "rr\n", len))
	{
		ft_rotate(check_a, 'x');
		ft_rotate(check_b, 'x');
	}
	else if (!ft_strncmp(str, "rra\n", len))
		ft_revrotate(check_a, 'x');
	else if (!ft_strncmp(str, "rrb\n", len))
		ft_revrotate(check_b, 'x');
	else if (!ft_strncmp(str, "rrr\n", len))
	{
		ft_revrotate(check_a, 'x');
		ft_revrotate(check_b, 'x');
	}
	else
		return (1);
	return (0);
}

void	ft_gnl_check(t_list **check_a, t_list **check_b)
{
	char		*str;
	int			len;
	static int	a;

	str = get_next_line(0);
	while (str)
	{
		len = ft_strlen(str);
		a = a + ft_swap_comp(check_a, check_b, str, len);
		a = a + ft_push_comp(check_a, check_b, str, len);
		a = a + ft_rot_comp(check_a, check_b, str, len);
		if (a >= 3)
		{
			free(str);
			write(2, "Error: <FALIED MOVE>\n", 21);
			exit(0);
		}
		a = 0;
		free(str);
		str = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_list		*check_a;
	t_list		*check_b;

	check_a = NULL;
	check_b = NULL;
	if (argc <= 1)
		return (0);
	ft_create_lst(&check_a, argc, argv);
	check_a = ft_trasform_num(check_a);
	if (check_list_order(check_a) == 0)
	{
		write(1, "OK\n", 3);
		exit(0);
	}
	ft_check_list(check_a);
	ft_gnl_check(&check_a, &check_b);
	if (check_list_order(check_a) == 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_lstclear(&check_a);
	ft_lstclear(&check_b);
	exit(0);
}
