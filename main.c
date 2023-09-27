/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:28:18 by carmas            #+#    #+#             */
/*   Updated: 2023/09/26 17:33:45 by carmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char **argv) {
  int i;
  struct stack *a, *b;
  char *line;

  // Initialisation des piles
  a = init_stack();
  b = init_stack();

  // Lecture des nombres à partir de l'entrée standard
  for (i = 1; i < argc; i++) {
    push(a, atoi(argv[i]));
  }

  // Tri des nombres
  while (!is_sorted(a)) {
    line = get_next_operation(a, b);
    printf("%s\n", line);
    free(line);
  }

  // Libération de la mémoire
  free_stack(a);
  free_stack(b);

  return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

// Définition des données.
typedef struct pile {
  int *elements;
  int size;
} Pile;

// Fonctions pour les opérations Push Swap.
void sa(Pile *a) {
  int temp = a->elements[0];
  a->elements[0] = a->elements[1];
  a->elements[1] = temp;
}

void pb(Pile *a, Pile *b) {
  b->elements[b->size++] = a->elements[0];
  a->elements[0] = 0;
}

void ra(Pile *a) {
  int temp = a->elements[0];
  for (int i = 0; i < a->size - 1; i++) {
    a->elements[i] = a->elements[i + 1];
  }
  a->elements[a->size - 1] = temp;
}

// Fonction principale.
void push_swap(int *nums, int n) {
  // Initialisation des piles.
  Pile a = {.elements = nums, .size = n};
  Pile b = {.elements = malloc(sizeof(int) * n), .size = 0};

  // Tri des entiers.
  while (a.size > 0) {
    // Trouvez le plus petit élément dans la pile A.
    int smallest = a.elements[0];
    for (int i = 1; i < a.size; i++) {
      if (a.elements[i] < smallest) {
        smallest = a.elements[i];
      }
    }

    // Si le plus petit élément est au sommet de la pile A, le poussez dans la pile B.
    if (a.elements[0] == smallest) {
      pb(&a, &b);
    }

    // Sinon, échangez les deux premiers éléments de la pile A.
    else {
      sa(&a);
    }
  }

  // Libérez la mémoire allouée.
  free(b.elements);
}

// Fonction de test.
int main() {
  int nums[] = {2, 1, 3, 6, 5, 8};
  int n = sizeof(nums) / sizeof(nums[0]);

  // Triez la liste d'entiers.
  push_swap(nums, n);

  // Imprimez la liste d'opérations.
  for (int i = 0; i < n; i++) {
    printf("%s\n", nums[i] == 0 ? "pb" : "sa");
  }

  return 0;
}

