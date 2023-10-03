/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:35:07 by carmas            #+#    #+#             */
/*   Updated: 2023/10/03 18:23:18 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	tmp;

	if (data->pilea->size < 2)
		return ;
	tmp = data->pilea->elements[data->pilea->size - 1];
	data->pilea->elements[data->pilea->size - 1] = data->pilea->elements[data->pilea->size - 2];
	data->pilea->elements[data->pilea->size - 2] = tmp;
}

void	sb(t_data *data)
{
	int	tmp;

	if (data->pileb->size < 2)
		return ;

	tmp = data->pileb->elements[data->pileb->size - 1];
	data->pileb->elements[data->pileb->size - 1] = data->pileb->elements[data->pileb->size - 2];
	data->pileb->elements[data->pileb->size -2] = tmp;
}

void	ss(t_data *data, t_data *datab)
{
	sa(data);
	sb(datab);
}
