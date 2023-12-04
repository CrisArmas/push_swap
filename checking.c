/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:10:28 by carmas            #+#    #+#             */
/*   Updated: 2023/11/30 14:10:04 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char **argv)
{
	size_t	count;

	count = 0;
	while (argv[count] != NULL)
	{
		if (ft_strlen(argv[count]) == 0
			|| ft_str_is_numeric(argv[count])
			|| INT_MAX < ft_atol(argv[count])
			|| INT_MIN > ft_atol(argv[count]))
			return (0);
		count++;
	}
	return (-1);
}

int	check_doublon(char **argv)
{
	size_t	count;
	size_t	count2;
	int		tmp;

	count = 0;
	while (argv[count] != NULL)
	{
		tmp = ft_atoi(argv[count]);
		count2 = count;
		while (argv[++count2] != NULL)
		{
			if (ft_atoi(argv[count2]) == tmp)
				return (0);
		}
		count++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
	{
		nptr++;
	}
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}

void	free_list(t_element *list)
{
	t_element	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
