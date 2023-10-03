/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:16:55 by carmas            #+#    #+#             */
/*   Updated: 2023/10/03 19:16:25 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_data *data)
{
	t_element	*lst;

	lst = data->pilea;
	while(lst)
	{
		printf("%d\n", lst->value);
		lst = lst->next;
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
//printf("\n%d\n", data->pilea->value);
}

int	main(int argc, char *argv[])
{
	int	i; 
	t_data	data;
	
	data.pilea = NULL;
	data.pileb = NULL;
	i = 1;
	if (argc == 1)
		return (write(1, "Erreur", 6));
	while (i < argc)
	{
		new_element(argv[i], &data);
		i++;
	}
//(void)data.pileb;

display(&data);
display(&data);
/*
//sa
sa(&data);
display(&data);
display(&data);

//sb
sb(&data);
display(&data);
display(&data);

//ss
ss(&data, &data);
display(&data);
display(&data);

return (0);
}

void    sa(t_data *data)
{
        int tmp;

        if (data->pilea->size < 2)
                return ;

        tmp = data->pilea->elements[data->pilea->size - 1];
        data->pilea->elements[data->pilea->size - 1] = data->pilea->elements[data->pilea->size - 2];
        data->pilea->elements[data->pilea->size - 2] = tmp;
}

void    sb(t_data *data)
{
        int tmp;

        if (data->pileb->size < 2)
                return ;

        tmp = data->pileb->elements[data->pileb->size - 1];
        data->pileb->elements[data->pileb->size - 1] = data->pileb->elements[data->pileb->size - 2];
        data->pileb->elements[data->pileb->size - 2] = tmp;
}

void    ss(t_data *data, t_data *datab)
{
        sa(data);
        sb(datab);
}
*/
