/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:57:48 by carmas            #+#    #+#             */
/*   Updated: 2023/10/27 15:02:00 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char **argv)
{
	size_t	count;
	char	sign;

	count = 0;
	while (argv[++count] != NULL)
	{
		sign = 0;
		if (argv[count][0] == '-')
			sign = 1;
		if (ft_strlen(argv[count] + sign) == 0 ||
				!ft_atol(argv[count]) ||
				!ft_str_is_numeric(argv[count] + sign))
			return (0);
	}
	return (check_doublon(argv));
}

int	check_doublon(char **argv)
{
	size_t	count;
	size_t	count2;
	int		tmp;

	count = 0;
	while (argv[++count] != NULL)
	{
		tmp = ft_atoi(argv[count]);
		count2 = count;
		while (argv[++count2] != NULL)
		{
			if (ft_atoi(argv[count2]) == tmp)
				return (0);
		}
	}
	return (1);
}

long	ft_atol(const char *str)
{
    long	result;
    int		sign;

    result = 0;
    sign = 1;
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result * sign);
}

int	ft_str_is_numeric(const char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}
size_t	ft_strlen(const char *s)
{
    size_t	len;

    len = 0;
    while (*s)
    {
        len++;
        s++;
    }
    return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
    if (s == NULL)
        return ;
    write(fd, s, ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
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

void	push_swap(t_data *data)
{
	t_element	*current_node_a;

	current_node_a = data->pilea;
	while (current_node_a)
	{
		pb(data);
		printf("pb\n");
		display(data);
		current_node_a = current_node_a->next;
	}
	while (data->pileb)
	{
		if (data->pileb->next && data->pileb->value < data->pileb->next->value)
		{
			sb(data);
			printf("sb\n");
			display(data);
		}
		else
		{
			pa(data);
			printf("pa\n");
			display(data);
		}
	}
}
/*
void	sort(t_data *data)
{
    int		min_value;
    int		min_index;

    while (data->pilea)
    {
        min_value = INT_MAX;
        min_index = 0;
        while (data->pilea)
        {
            if (data->pilea->value < min_value)
            {
                min_value = data->pilea->value;
                min_index = 1;
            }
            data->pilea = data->pilea->next;
        }
        while (min_index--)
            pb(data);
    }
    while (data->pileb)
        pa(data);
    display(data);
}
*/
void	sort(t_data *data)
{
	if (is_sorted(data))
		return ;
	if (get_len(data->pilea) == 2)
	{
		if (data->pilea->value > data->pilea->next->value)
			sa(data);
		return ;
	}
	else if (get_len(data->pilea) == 3)
		sort_three(data);
	else if (get_len(data->pilea) <= 4)
		sort_four(data);
	else if (get_len(data->pilea) <= 5)
		sort_five(data);
	else if (get_len(data->pilea) <= 100)
		sort_hundred(data);
}

