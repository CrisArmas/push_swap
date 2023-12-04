/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:51:24 by carmas            #+#    #+#             */
/*   Updated: 2023/11/30 16:27:13 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_element *pile)
{
	int				max_val;
	t_element		*current;

	max_val = pile->value;
	current = pile->next;
	while (current != NULL)
	{
		if (current->value > max_val)
		{
			max_val = current->value;
		}
		current = current->next;
	}
	return (max_val);
}

int	find_min(t_element *pile)
{
	int			min_val;
	t_element	*current;

	min_val = pile->value + 1;
	current = pile;
	while (current != NULL)
	{
		if (current->value < min_val)
		{
			current->index = 0;
			min_val = current->value;
		}
		current = current->next;
	}
	return (min_val);
}

void	find_min_value(t_data *data, int i)
{
	long long		min_val;
	t_element		*current;
	t_element		*tmp;

	min_val = (long long)data->max_value + 1;
	current = data->pilea;
	while (current != NULL)
	{
		if (current->value < min_val && current->value > data->min_value)
		{
			min_val = current->value;
			tmp = current;
		}
		current = current->next;
	}
	tmp->index = i;
	data->min_value = min_val;
}

void	fill_index(t_data *data)
{
	int				i;
	// t_element		*current;

	i = 1;
	while (i < data->total)
	{
		find_min_value(data, i);
		i++;
	}
	// current = data->pilea;
	// while (current)
	// 	current = current->next;
}

void	get_min_max(t_data *data)
{
	int	i;

	i = 0;
	while (data->args[i] != NULL)
	{
		i++;
	}
	data->total = i;
	data->min_value = find_min(data->pilea);
	data->max_value = find_max(data->pilea);
}
