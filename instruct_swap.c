/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:31:07 by carmas            #+#    #+#             */
/*   Updated: 2023/10/26 15:58:09 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	t_element	*tmp;

	if (data->pilea != NULL && data->pilea->next != NULL)
	{
		tmp = data->pilea;
		data->pilea = data->pilea->next;
		tmp->next = data->pilea->next;
		data->pilea->next = tmp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_data *data)
{
	t_element	*first;
	t_element	*second;

	if (data->pileb == NULL || data->pileb->next == NULL)
		return ;
	first = data->pileb;
	second = first->next;
	first->next = second->next;
	second->next = first;
	data->pileb = second;
	write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
	write(1, "ss\n", 3);
}
