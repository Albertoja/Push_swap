/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:19:53 by aespinos          #+#    #+#             */
/*   Updated: 2022/06/22 19:19:54 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

static unsigned long long int	ft_check(unsigned long long int result, int sig)
{
	if (result > 2147483647 && sig < 0)
		return (0);
	else if (result > 2147483648 && sig > 0)
		return (-1);
	else
		return (result);
}

int	ft_atoi(const char *str)
{
	int						x;
	int						sig;
	unsigned long long int	result;
	{
		x = 0;
		sig = 1;
		result = 0;
		while (str[x] == ' ' || str[x] == '\t' || str[x] == '\n'
			|| str[x] == '\v' || str[x] == '\f' || str[x] == '\r')
			x++;
		while (str[x] == '+' || str[x] == '-')
		{
			if (str[x] == '-')
				sig = sig * (-1);
			if (str[x + 1] == '+' || str[x + 1] == '-')
				return (0);
			x++;
		}
		while (str[x] >= '0' && str[x] <= '9')
		{
			result = (str[x] - 48) + (result * 10);
			x++;
		}
		return ((int)ft_check(result, sig) * sig);
	}
}

int	ft_isnumber(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s++) == 0)
			return (0);
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n && s1[a] && s2[a])
	{
		if (s1[a] != s2[a])
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		a++;
	}
	if (a < n)
		return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	return (0);
}
