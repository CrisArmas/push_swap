/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:47:59 by carmas            #+#    #+#             */
/*   Updated: 2023/11/22 14:21:01 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_add(t_data *data)
{
	ra(data);
	sa(data);
	rra(data);
}

void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->pilea->value;
	b = data->pilea->next->value;
	c = data->pilea->next->next->value;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
		sort_three_add(data);
	else if (b < a && a < c)
		sa(data);
	else if (b < c && c < a)
		ra(data);
	else if (c < a && a < b)
		rra(data);
	else
	{
		sa(data);
		rra(data);
	}
}

void	sort_four(t_data *data)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	max;

	a = data->pilea->value;
	b = data->pilea->next->value;
	c = data->pilea->next->next->value;
	d = data->pilea->next->next->next->value;
	max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	if (d > max)
		max = d;
	while (data->pilea->value != max)
	{
		ra(data);
	}
	pb(data);
	sort_three(data);
	pa(data);
	ra(data);
}

void	ft_radix(t_data *data)
{
	int				max_bits;
	int				i;
	int				len;
	t_element		*current;

	max_bits = 0;
	while ((get_len(data->pilea) - 1) >> max_bits != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		len = get_len(data->pilea);
		while (len--)
		{
			current = data->pilea;
			if (((current->index >> i) & 1) == 1)
				ra(data);
			else
				pb(data);
		}
		while (data->pileb)
			pa(data);
	}
}
