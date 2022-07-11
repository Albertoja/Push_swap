/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:20:06 by aespinos          #+#    #+#             */
/*   Updated: 2022/07/11 19:10:22 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_num_same(t_list *stack_a)
{
	t_list	*aux;

	while (stack_a)
	{
		aux = stack_a->next;
		while (aux)
		{
			if (stack_a->content == aux->content)
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			aux = aux->next;
		}
		stack_a = stack_a->next;
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
		return (0);
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
				write(2, "Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
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
		write(2, "Error\n", 6);
		exit(0);
	}
	return ((int)(ans * sign));
}

int	ft_check_list(t_list *stack_a)
{
	if (!stack_a)
		exit(0);
	if (ft_num_same(stack_a) != 0)
		return (1);
	else if (check_list_order(stack_a) != 0)
		return (1);
	write(2, "Error\n", 6);
	exit(0);
}
