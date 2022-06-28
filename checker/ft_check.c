/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:20:06 by aespinos          #+#    #+#             */
/*   Updated: 2022/06/28 15:44:49 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_num_same(t_list *stack_a)
{
	t_list	*aux_01;
	t_list	*aux_02;

	aux_01 = stack_a;
	aux_02 = stack_a->next;
	while (aux_01 && aux_02)
	{
		while (aux_02)
		{
			if (aux_01->content == aux_02->content)
			{
				write(2, "Error: same number\n", 19);
				exit(0);
			}
			aux_02 = aux_02->next;
		}
		aux_02 = aux_01->next->next;
		aux_01 = aux_01->next;
	}
	return (0);
}

int	check_list_order(t_list *stack)
{
	t_list	*aux;
	int		comp;

	comp = 0;
	aux = stack->next;
	while (aux)
	{
		if (aux->content < stack->content)
			comp += 1;
		aux = aux->next;
		stack = stack->next;
	}
	if (comp + 1 == ft_lstsize(stack))
	{
		return (0);
	}
	return (1);
}

void	ft_check_letters(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
		{
			if (ft_strlen(numbers[i]) > 11 || ft_isnumber(numbers[i]) == 0)
			{
				ft_free(numbers);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int	ft_check_list(t_list *stack_a)
{
	if (!stack_a)
		exit(0);
	if (ft_num_same(stack_a) != 0)
		return (1);
	else if (check_list_order(stack_a) != 0)
		return (1);
	return (0);
}

int	ft_atoi_check(const char *str, char **numbers)
{
	long int	ans;
	int			sign;

	ans = 0;
	sign = 1;
	if (*str == 45)
	{
		sign *= -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str > 47 && *str < 58)
	{
		ans = ans * 10 + (*str - 48);
		str++;
	}
	if (ans * sign > 2147483647 || ans * sign < -2147483648)
	{
		ft_free(numbers);
		write(2, "Error: int num\n", 15);
		exit(0);
	}
	return ((int)(ans * sign));
}
