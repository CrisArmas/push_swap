/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:16:55 by carmas            #+#    #+#             */
/*   Updated: 2023/10/27 15:54:25 by carmas           ###   ########.fr       */
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

	element = (t_element *)malloc(sizeof(t_element));
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
		element->next = data->pilea;
		data->pilea = element;
	}
}

//(write(2, "Erreur", 6));
/*
int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;

	data.pilea = NULL;
	data.pileb = NULL;
	i = 1;
	if (argc == 1) // If there is no arguments
		return (0); // Exit the program
	while (i < argc)  
	{
		new_element(argv[i], &data);
		i++;
	}
	if (data.pilea != NULL && data.pilea->next != NULL)
		sort(&data);
	return (0);
}
*/
int	main(int argc, char *argv[])
{
    t_data	data;

    data.pilea = NULL;
    data.pileb = NULL;
    if (argc == 1) // If there is no arguments
        return (0); // Exit the program
    if (!check_arg(argv)) // Check if arguments are valid
    {
        write(2, "Error\n", 6);
        return (1);
    }
    if (!check_doublon(argv)) // Check if there are any duplicates
    {
        write(2, "Error\n", 6); // If there are duplicates, exit the program
        return (1);
    }
    while (*argv)
    {
        new_element(*argv, &data);
        argv++;
    }
    if (data.pilea != NULL && data.pilea->next != NULL)
	{
		if (is_sorted(&data)==0)
			return (0);
	}
		sort(&data);
    return (0);
}