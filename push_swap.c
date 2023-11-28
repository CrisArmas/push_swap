/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:16:55 by carmas            #+#    #+#             */
/*   Updated: 2023/11/22 11:40:28 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_data *data)
{
	t_element	*current_node_a;
	t_element	*current_node_b;

	printf("Pile A :\tPile B :\n");
	current_node_a = data->pilea;
	current_node_b = data->pileb;
	while (current_node_a || current_node_b)
	{
		if (current_node_a)
		{
			printf("%*d", 4, current_node_a->value);
			current_node_a = current_node_a->next;
		}
		else
		{
			printf("%*s", 4, "");
		}
		printf("%*s", 10, "");
		if (current_node_b)
		{
			printf("%*d", 6, current_node_b->value);
			current_node_b = current_node_b->next;
		}
		printf("\n");
	}
}

void	new_element(char *arg, t_data *data)
{
	t_element	*element;
	t_element	*tmp;

	element = (t_element *)malloc(sizeof(t_element));
	tmp = NULL;
	if (!element)
		return ;
	element->next = NULL;
	element->value = ft_atoi(arg);
	if (!(data->pilea))
	{
		data->pilea = element;
	}
	else
	{
		tmp = data->pilea;
		while (data->pilea->next)
			data->pilea = data->pilea->next;
		data->pilea->next = element;
		data->pilea = tmp;
	}
}

void	free_stacks(t_data *data)
{
	t_element	*tmp;

	while (data->pilea)
	{
		tmp = data->pilea;
		data->pilea = data->pilea->next;
		free(tmp);
	}
	while (data->pileb)
	{
		tmp = data->pileb;
		data->pileb = data->pileb->next;
		free(tmp);
	}
}

void	main_suite(t_data *data)
{
	if (data->pilea != NULL && data->pilea->next != NULL)
	{
		if (is_sorted(data))
			return ;
		get_min_max(data);
		fill_index(data);
		sort(data);
	}
	free_split(data->args);
	free_stacks(data);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;

	i = 0;
	data.pilea = NULL;
	data.pileb = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		data.args = ft_split(argv[1], ' ');
	else
		data.args = ++argv;
	if (!check_arg(data.args))
		return (write(2, "Error\n", 6));
	if (!check_doublon(data.args))
		return (write(2, "Error\n", 6));
	while (data.args[i])
	{
		new_element(data.args[i], &data);
		i++;
	}
	main_suite(&data);
}
