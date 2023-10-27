/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_revrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:37:09 by carmas            #+#    #+#             */
/*   Updated: 2023/10/26 15:58:49 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_data *data)
{
	t_element	*last_node;
	t_element	*before_last_node;

	if (data->pilea != NULL && data->pilea->next != NULL)
	{
		last_node = data->pilea;
		before_last_node = NULL;
		while (last_node->next != NULL)
		{
			before_last_node = last_node;
			last_node = last_node->next;
		}
		last_node->next = data->pilea;
		data->pilea = last_node;
		before_last_node->next = NULL;
	}
}

void	rra(t_data *data)
{
	t_element	*first;
	t_element	*last;

	if (data->pilea && data->pilea->next)
	{
		first = data->pilea;
		last = first;
		while (last->next)
		{
			first = last;
			last = last->next;
		}
		first->next = NULL;
		last->next = data->pilea;
		data->pilea = last;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_data *data)
{
	t_element	*first;
	t_element	*last;

	if (data->pileb && data->pileb->next)
	{
		first = data->pileb;
		last = first;
		while (last->next)
		{
			first = last;
			last = last->next;
		}
		first->next = NULL;
		last->next = data->pileb;
		data->pileb = last;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
	write(1, "rrr\n", 4);
}
