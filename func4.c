/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:56:25 by carmas            #+#    #+#             */
/*   Updated: 2023/11/30 16:28:28 by carmas           ###   ########.fr       */
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
	int			i;

	i = 0;
	while (i < 5)
	{
		if (data->pilea->index == 0 || data->pilea->index == 1)
			pb(data);
		else
			ra(data);
		i++;
	}
	sort_three(data);
	if (data->pileb->index == 0)
		rb(data);
	pa(data);
	pa(data);
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
