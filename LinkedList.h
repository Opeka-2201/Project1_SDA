/* ========================================================================= *
 * Linked List
 * ========================================================================= */

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stddef.h>

/** Node (opaque) structure */
typedef struct Node_t Node;

/** List (opaque) structure */
typedef struct List_t List;

/* ------------------------------------------------------------------------- *
 * Create an empty list
 *
 * RETURN
 * list         A pointer to a list.
 * ------------------------------------------------------------------------- */
List* llCreateEmpty(void);

/* ------------------------------------------------------------------------- *
 * Create a random list of integers (from 0 to length-1).
 *
 * All the nodes of the list must eventually be free using free(). 
 * A complete list can be freed using freeList().
 *
 * PARAMETERS
 * length       Number of elements in the list
 *
 * RETURN
 * list         A pointer to the node at the head of the list
 * ------------------------------------------------------------------------- */
List* llCreateRandom(size_t length);

/* ------------------------------------------------------------------------- *
 * Create a sorted of integers (from 0 to length-1).
 *
 * All the nodes of the list must eventually be free using free(). 
 * A complete list can be freed using freeList().
 *
 * PARAMETERS
 * length       Number of elements in the list
 *
 * RETURN
 * list         A pointer to the node at the head of the list
 * ------------------------------------------------------------------------- */
List* llCreateSorted(size_t length);

/* ------------------------------------------------------------------------- *
 * Free a linked list but NOT its nodes
 *
 * PARAMETERS
 * list         A pointer to the list.
 * ------------------------------------------------------------------------- */
void llFree(List* list);

/* ------------------------------------------------------------------------- *
 * Free a linked list and all its nodes
 *
 * PARAMETERS
 * list         A pointer to the list.
 * ------------------------------------------------------------------------- */
void llFreeAll(List* list);

/* ------------------------------------------------------------------------- *
 * Insert the node at the beginning of the list.
 *
 * PARAMETERS
 * list         A pointer to a list.
 * node         A pointer to a node.
 * ------------------------------------------------------------------------- */
void llInsertFirst(List* list, Node* node);

/* ------------------------------------------------------------------------- *
 * Insert the node at the end of the list.
 *
 * PARAMETERS
 * list         A pointer to a list.
 * node         A pointer to a node.
 * ------------------------------------------------------------------------- */
void llInsertLast(List* list, Node* node);

/* ------------------------------------------------------------------------- *
 * Remove the node at the beginning of the list.
 *
 * PARAMETERS
 * list         A pointer to a list.
 * node         A pointer to a node.
 *
 * RETURN
 * node         A pointer to the removed node 
 * ------------------------------------------------------------------------- */
Node* llRemoveFirst(List* list); 

/* ------------------------------------------------------------------------- *
 * Add node2 after node1 in the list. node1 is expected to be a node of the
 * list. If not, the result is undetermined.
 *
 * PARAMETERS
 * list         A pointer to a list
 * node1        A pointer to the node after which the node will be added
 * node2        A pointer to the node to be added
 * ------------------------------------------------------------------------- */
void llInsertAfter(List * list, Node* node1, Node *node2);

/* ------------------------------------------------------------------------- *
 * Extract and return the node after a node in the list. Return NULL if the 
 * returned node is the last one. The node is expected to be a node from the
 * list. If not, the result is undetermined.
 *
 * PARAMETERS
 * list         A pointer to a list
 * node         A pointer to a node in the list
 * 
 * RETURN
 * node         A pointer to removed node
 * ------------------------------------------------------------------------- */
Node *llRemoveAfter(List *list, Node *node);

/* ------------------------------------------------------------------------- *
 * Concatenate the second list at the end of the first (leaving the second empty).
 *
 * PARAMETERS
 * list1        A pointer to the first list.
 * list2        A pointer to the second list. 
 * ------------------------------------------------------------------------- */
void llConcatenate(List* list1, List* list2);

/* ------------------------------------------------------------------------- *
 * Return a pointer to the head node of the list.
 *
 * PARAMETERS
 * list         A pointer to a list.
 * 
 * RETURN
 * head         A pointer to the head node.
 * ------------------------------------------------------------------------- */
Node* llHead(const List* list);

/* ------------------------------------------------------------------------- *
 * Return a pointer to the tail node of the list.
 *
 * PARAMETERS
 * list         A pointer to a list.
 * 
 * RETURN
 * tail         A pointer to the tail node.
 * ------------------------------------------------------------------------- */
Node* llTail(const List* list);

/* ------------------------------------------------------------------------- *
 * Return the size of the list
 *
 * PARAMETERS
 * list         A pointer to a list.
 * 
 * RETURN
 * length       The number of nodes in the list
 * ------------------------------------------------------------------------- */
size_t llLength(const List* list);

/* ------------------------------------------------------------------------- *
 * Return a pointer to the node following $node in the list.
 *
 * PARAMETERS
 * node         A pointer to a node.
 * 
 * RETURN
 * node         A pointer to the next node.
 * ------------------------------------------------------------------------- */
Node* llNext(const Node* node);

/* ------------------------------------------------------------------------- *
 * Return the key associated with a node.
 *
 * PARAMETERS
 * node         A pointer to a node.
 *
 * RETURN
 * key          The key 
 * ------------------------------------------------------------------------- */
int llKey(const Node* node);

#endif // !_LINKED_LIST_H_
