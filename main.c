#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "SortLL.h"
#include "LinkedList.h"

/* Prototypes */

/* ------------------------------------------------------------------------- *
 * Compute the CPU time (in seconds) used by the Sort function.
 *
 * PARAMETERS
 * list         Linked list to sort
 *
 * RETURN
 * seconds      The number of seconds used by Sort
 * ------------------------------------------------------------------------- */
static double cpuTimeUsedToSort(List* list)
{
    clock_t start = clock();
    sortLL(list);
    return ((double) (clock() - start)) / CLOCKS_PER_SEC;
}


/* ------------------------------------------------------------------------- *
 * Check that a linked list is sorted and has the correct size
 *
 * PARAMETERS
 * list         Linked list to check
 *
 * RETURN
 * flag         1 if the list is sorted, 0 otherwise
 * ------------------------------------------------------------------------- */
static int checkSortedList(List* list)
{

  Node *pos = llHead(list);
  
  for (size_t i = 0; i<(llLength(list)-2); i++, pos = llNext(pos)) {
    if (pos && llNext(pos)) {
      if (llKey(pos) > llKey(llNext(pos))) {
	printf("The list is not sorted\n");
	return 0;
      }
    } else {
      printf("The list is shorter than expected (l=%d)\n", (int)i);
      return 0;
    }
  }
  
  return 1;
}

static void printLL(List *list) {
  Node *pos = llHead(list);
  while (pos) {
    printf(" %d", llKey(pos));
    pos = llNext(pos);
  }
  printf("\n");
}


/* ------------------------------------------------------------------------- *
 * Main
 * ------------------------------------------------------------------------- */
int main(int argc, char** argv)
{
   //--------------------------- PARSE COMMAND LINE -------------------------
    unsigned seed = (unsigned) time(NULL);
    size_t sizeList = 10;
    int sorted = 0;
    int argi = 1; // Ideally this should be a size_t (historical reasons)
    while(argi < argc)
    {
        if(strcmp(argv[argi], "-s") == 0)
        {
            size_t inputSize;
            if(sscanf (argv[++argi], "%zu", &inputSize) != 1)
            {
                fprintf(stderr, "%s\n", "Aborting; size should be an unsigned "
                                        "integer.");
                exit(EXIT_FAILURE);
            }
            sizeList = inputSize;
        } else if(strcmp(argv[argi], "-r") == 0) {
            unsigned inputSeed;
            if(sscanf (argv[++argi], "%u", &inputSeed) != 1)
            {
                fprintf(stderr, "%s\n", "Aborting; the random seed should be an "
                                        "unsigned integer.");
                exit(EXIT_FAILURE);
            }
            seed = inputSeed;
        } else if (strcmp(argv[argi], "-sorted") == 0) {
	    sorted = 1;
	} else {
            fprintf(stderr, "%s '%s'\n", "Aborting; unknown parameter",
                    argv[argi]);
            fprintf(stderr, "%s %s %s\n", "Usage:", argv[0], "[-s size] "
                    "[-r random_seed]\n");
            exit(EXIT_FAILURE);
        }
        argi++;
    }

    srand(seed);//Use an integer seed to get a fix sequence

    printf("Size of the list: %d\n", (int) sizeList);

    List* list;
    if (sorted)
      list = llCreateSorted(sizeList);
    else
      list = llCreateRandom(sizeList);

    if (sizeList<50)
      printLL(list);
	
    const double sec = cpuTimeUsedToSort(list);
    printf("CPU Time: %f\n", sec);

    if (sizeList<50)
      printLL(list);
    if (checkSortedList(list))
      printf("The list is correctly sorted\n");

    llFreeAll(list);

    return 0;
}
