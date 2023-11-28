/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <carmas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:18:08 by carmas            #+#    #+#             */
/*   Updated: 2023/11/22 13:58:43 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_element
{
	int					value;
	int					index;
	struct s_element	*next;
}						t_element;

typedef struct s_data
{
	t_element			*pilea;
	t_element			*pileb;
	char				**args;
	int					min_value;
	int					max_value;
	int					total;
	int					min_index;
}						t_data;

int						ft_atoi(const char *nptr);
int						check_arg(char **argv);
int						ft_str_is_numeric(const char *str);
long					ft_atol(const char *str);
int						check_doublon(char **argv);
char					**ft_split(char const *s, char c);
size_t					ft_strlen(const char *s);
void					new_element(char *arg, t_data *data);
void					display(t_data *data);
void					ft_putchar(char c);
void					sort_three_add(t_data *data);
void					sa(t_data *data);
void					rotate(t_data *data);
void					reverse_rotate(t_data *data);
void					pa(t_data *data);
void					pb(t_data *data);
void					sb(t_data *data);
void					ss(t_data *data);
void					sort(t_data *data);
void					ra(t_data *data);
void					rb(t_data *data);
void					rr(t_data *data);
void					rra(t_data *data);
void					rrb(t_data *data);
void					rrr(t_data *data);
void					sort_three(t_data *data);
void					sort_four(t_data *data);
void					sort_five(t_data *data);
void					push_min_to_a(t_data *data);
void					ft_radix(t_data *data);
void					fill_index(t_data *data);
void					free_split(char **str);
int						get_min(t_element *pile);
int						get_max(t_element *pile);
int						get_min_index(t_element *pile);
int						get_len(t_element *pile);
int						is_sorted(t_data *data);
void					get_min_max(t_data *data);
int						find_max(t_element *pile);
void					add_back_first_half(t_data *data, int i);
void					add_back_second_half(t_data *data, int i);	
void					add_back(t_data *data, int i);

#endif
