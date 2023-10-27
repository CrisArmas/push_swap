/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:47:59 by carmas            #+#    #+#             */
/*   Updated: 2023/10/27 15:56:29 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	sort_three(t_data *data)
{
	if (data->pilea->value > data->pilea->next->value
		&& data->pilea->next->value < data->pilea->next->next->value
		&& data->pilea->value < data->pilea->next->next->value)
		sa(data);
	else if (data->pilea->value > data->pilea->next->value
		&& data->pilea->next->value > data->pilea->next->next->value
		&& data->pilea->value > data->pilea->next->next->value)
	{
		sa(data);
		rra(data);
	}
	else if (data->pilea->value > data->pilea->next->value
		&& data->pilea->next->value < data->pilea->next->next->value
		&& data->pilea->value > data->pilea->next->next->value)
		ra(data);
	else if (data->pilea->value < data->pilea->next->value
		&& data->pilea->next->value > data->pilea->next->next->value
		&& data->pilea->value < data->pilea->next->next->value)
	{
		sa(data);
		ra(data);
	}
	else if (data->pilea->value > data->pilea->next->value
		&& data->pilea->next->value > data->pilea->next->next->value
		&& data->pilea->value > data->pilea->next->next->value)
	{
		ra(data);
		sa(data);
		rra(data);
	}
}
*/
void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->pilea->value;
	b = data->pilea->next->value;
	c = data->pilea->next->next->value;
	if (a > b && b < c && a < c)
		sa(data);
	else if (a > b && b > c && a > c)
	{
		sa(data);
		rra(data);
	}
	else if (a > b && b < c && a > c)
		ra(data);
	else if (a < b && b > c && a < c)
	{
		sa(data);
		ra(data);
	}
	else if (a > b && b > c && a > c)
	{
		ra(data);
		sa(data);
		rra(data);
	}
}

void	sort_four(t_data *data)
{
	pb(data);
	sort_three(data);
	pa(data);
}

void	sort_five(t_data *data)
{
	pb(data);
	pb(data);
	sort_three(data);
	pa(data);
	pa(data);
}

void	sort_hundred(t_data *data)
{
	int	chunk_size;
	int	chunks;
	int	i;

	chunk_size = 5;
	chunks = 20;
	i = 0;
	while (i < chunks)
	{
		push_chunk(data, chunk_size);
		i++;
	}
	while (data->pileb)
		push_min_to_a(data);
}

void	push_chunk(t_data *data, int chunk_size)
{
	int	i;
	int	min;
	int	max;

	min = get_min(data->pilea);
	max = get_max(data->pilea);
	i = 0;
	while (i < chunk_size && data->pilea)
	{
		if (data->pilea->value >= min && data->pilea->value <= max)
		{
			pb(data);
			i++;
		}
		else
			ra(data);
	}
}

void	push_min_to_a(t_data *data)
{
	int	min_index;
	int	len;

	len = get_len(data->pileb);
	min_index = get_min_index(data->pileb);
	if (min_index <= len / 2)
		while (min_index--)
			rb(data);
	else
		while (len - min_index++)
			rrb(data);
	pa(data);
}

int	get_min(t_element *pile)
{
	int	min;

	min = pile->value;
	while (pile)
	{
		if (pile->value < min)
			min = pile->value;
		pile = pile->next;
	}
	return (min);
}

int	get_max(t_element *pile)
{
	int	max;

	max = pile->value;
	while (pile)
	{
		if (pile->value > max)
			max = pile->value;
		pile = pile->next;
	}
	return (max);
}

int	get_min_index(t_element *pile)
{
	int	min;
	int	index;

	min = pile->value;
	index = 0;
	while (pile)
	{
		if (pile->value < min)
		{
			min = pile->value;
			index = 0;
		}
		pile = pile->next;
		index++;
	}
	return (index);
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
/*
int	is_sorted(t_data *data)
{
	t_element	*current_node_a;

	current_node_a = data->pilea;
	while (data->pilea->next)
	{
		if (data->pilea->value > data->pilea->next->value)
		{
			data->pilea = current_node_a;
			return (0);
		}
		data->pilea = data->pilea->next;
	}
	data->pilea = current_node_a;
	return (1);
}
*/
int	is_sorted(t_data *data)
{
    t_element	*current_node_a;

    current_node_a = data->pilea;
    while (current_node_a->next)
    {
        if (current_node_a->value > current_node_a->next->value) 
        {
            data->pilea = current_node_a;
			return (0);
        }
        current_node_a = current_node_a->next;
    }
    //data->pilea = current_node_a;
    return (1);
}
