/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:18:08 by carmas            #+#    #+#             */
/*   Updated: 2023/10/03 19:09:26 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_element
{
	int	value;
	struct s_element	*next;	
}	t_element;

typedef struct	s_data
{
	t_element	*pilea;
	t_element	*pileb;
}	t_data;

int	ft_atoi(const char *nptr);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data, t_data *datab);


#endif
