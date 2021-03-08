#include "SortLL.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

static void merge_node(Node **tab, int lo, int mid, int hi, Node **aux);
static void mergesort_aux_node(Node **tab, int lo, int hi, Node **aux);
static void mergesortnode(Node **tab, int n);

static void merge_node(Node **tab, int lo, int mid, int hi, Node **aux) {
  int i = lo, j = mid;

  for (int k = lo; k <= hi; k++)
    if (i == mid)
      aux[k] = tab[j++];
    else if (j == hi + 1)
      aux[k] = tab[i++];
    else if (llKey(tab[i]) <= llKey(tab[j]))
      aux[k] = tab[i++];
    else
      aux[k] = tab[j++];

  for (int k = lo; k <= hi; k++)
    tab[k] = aux[k];
  
}
  
static void mergesort_aux_node(Node **tab, int lo, int hi, Node **aux) {
  int n = hi - lo + 1;
  if (n <= 1)
    return;
  int mid = lo + (n + 1) / 2;
  mergesort_aux_node(tab, lo, mid - 1, aux);
  mergesort_aux_node(tab, mid, hi, aux);
  merge_node(tab, lo, mid, hi, aux);
}

static void mergesortnode(Node **tab, int n) {
  Node *aux[n];
  mergesort_aux_node(tab, 0, n-1, aux);
}

void sortLL(List *list) {
  size_t length = llLength(list);
  Node **array = malloc(length * sizeof(Node *));

  if (array == NULL) {
    printf("Erreur d'allocation mémoire dans sortLLbyArray\n");
  }

  for (size_t i = 0; llLength(list) > 0; i++)
    array[i] = llRemoveFirst(list);

  mergesortnode(array, length);

  for (size_t i = 0; i<length; i++)
    llInsertLast(list, array[i]);

  free(array);
}

