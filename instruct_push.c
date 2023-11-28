/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:33:34 by carmas            #+#    #+#             */
/*   Updated: 2023/11/09 15:23:46 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	t_element	*first;

	if (data->pileb == NULL)
		return ;
	first = data->pileb;
	data->pileb = first->next;
	first->next = data->pilea;
	data->pilea = first;
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	t_element	*element;

	if (data->pilea == NULL || data->pilea->next == NULL)
		return ;
	element = data->pilea;
	data->pilea = data->pilea->next;
	element->next = data->pileb;
	data->pileb = element;
	write(1, "pb\n", 3);
}
