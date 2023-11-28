/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:56:25 by carmas            #+#    #+#             */
/*   Updated: 2023/11/22 15:28:02 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back_first_half(t_data *data, int i)
{
	int	j;

	j = 0;
	while (i--)
	{
		ra(data);
		j++;
	}
	pa(data);
	while (j > 0)
	{
		rra(data);
		j--;
	}
}

void	add_back_second_half(t_data *data, int i)
{
	int	j;

	j = 0;
	while (i++ < get_len(data->pilea))
	{
		rra(data);
		j++;
	}
	pa(data);
	while (j >= 0)
	{
		ra(data);
		j--;
	}
}

void	add_back(t_data *data, int i)
{
	if (i <= get_len(data->pilea) / 2)
		add_back_first_half(data, i);
	else
		add_back_second_half(data, i);
}

void	sort_five(t_data *data)
{
	t_element	*current;
	int			i;

	pb(data);
	pb(data);
	sort_three(data);
	i = 0;
	current = data->pilea;
	while (current && data->pileb->index > current->index)
	{
		i++;
		current = current->next;
	}
	add_back(data, i);
	i = 0;
	current = data->pilea;
	while (current && data->pileb->index > current->index)
	{
		i++;
		current = current->next;
	}
	add_back(data, i);
}

int	get_len(t_element *pile)
{
	int	len;

	len = 0;
	while (pile)
	{
		len++;
		pile = pile->next;
	}
	return (len);
}
