/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:16:55 by carmas            #+#    #+#             */
/*   Updated: 2023/11/30 16:32:18 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	main_suite(t_data *data, int argc)
{
	if (data->pilea != NULL && data->pilea->next != NULL)
	{
		if (is_sorted(data))
		{
			if (argc == 2)
				free_split(data);
			free_stacks(data);
			return ;
		}
		get_min_max(data);
		fill_index(data);
		sort(data);
	}
	if (argc == 2)
		free_split(data);
	free_stacks(data);
}

int	check_error(t_data *data, int argc)
{
	if (check_arg(data->args) == 0)
	{
		if (argc == 2)
			free_split(data);
		return (write(2, "Error\n", 6));
	}
	if (!check_doublon(data->args))
	{
		if (argc == 2)
			free_split(data);
		return (write(2, "Error\n", 6));
	}
	return (0);
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
	if (check_error(&data, argc) != 0)
		return (0);
	while (data.args[i])
		new_element(data.args[i++], &data);
	main_suite(&data, argc);
}
