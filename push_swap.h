/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:29:56 by carmas            #+#    #+#             */
/*   Updated: 2023/09/26 17:33:01 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

// Structure représentant une pile
struct stack {
  int *elements;
  int size;
};

// Initialise une pile
struct stack *init_stack();

// Libère la mémoire allouée pour une pile
void free_stack(struct stack *stack);

// Insère un élément au sommet d'une pile
void push(struct stack *stack, int element);

// Supprime l'élément au sommet d'une pile
int pop(struct stack *stack);

// Vérifie si une pile est triée
int is_sorted(struct stack *stack);

// Récupère la prochaine opération à effectuer pour trier une pile
char *get_next_operation(struct stack *a, struct stack *b);

#endif
