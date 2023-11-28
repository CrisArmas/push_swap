/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:35:07 by carmas            #+#    #+#             */
/*   Updated: 2023/11/17 16:32:59 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_data *data)
{
	t_element	*last_node;

	if (data->pilea != NULL && data->pilea->next != NULL)
	{
		last_node = data->pilea;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = data->pilea;
		data->pilea = data->pilea->next;
		last_node->next->next = NULL;
	}
}

void	ra(t_data *data)
{
	t_element	*first;
	t_element	*last;

	if (data->pilea && data->pilea->next)
	{
		first = data->pilea;
		last = first;
		while (last->next)
			last = last->next;
		data->pilea = first->next;
		first->next = NULL;
		last->next = first;
		write(1, "ra\n", 3);
	}
}

void	rb(t_data *data)
{
	t_element	*first;
	t_element	*last;

	if (data->pileb && data->pileb->next)
	{
		first = data->pileb;
		last = first;
		while (last->next)
			last = last->next;
		data->pileb = first->next;
		first->next = NULL;
		last->next = first;
		write(1, "rb\n", 3);
	}
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	write(1, "rr\n", 3);
}
