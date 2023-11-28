/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:10:34 by carmas            #+#    #+#             */
/*   Updated: 2023/11/22 14:11:36 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_data *data)
{
	t_element	*current_node_a;

	current_node_a = data->pilea;
	while (current_node_a->next)
	{
		if (current_node_a->value > current_node_a->next->value)
		{
			return (0);
		}
		current_node_a = current_node_a->next;
	}
	data->pilea = current_node_a;
	return (1);
}

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
	else
		ft_radix(data);
}
