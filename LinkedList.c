
#include "LinkedList.h"
#include<stdlib.h>

struct Node_t {
  Node* next;
  int key;
};

struct List_t {
  Node* head;
  Node* tail;
  size_t length;
};

/** 
 * Create a node. 
 */
static Node* createNode(Node* next, int key) {
  Node* node = malloc(sizeof(Node));
  if (!node) {
    return NULL;
  }
  node->next = next;
  node->key = key;
  
  return node;
}

/**
 * Create a list.
 */
static List* createList(Node* head, Node* tail, size_t length) {
  List* list = malloc(sizeof(List));
  if (!list) {
    return NULL;
  }
  list->head = head;
  list->tail = tail;
  list->length = length;
  return list;
}

List* llCreateEmpty() {
  return createList(NULL, NULL, 0);
}

void llInsertFirst(List* list, Node* node) {
  if (!list->head) {
    list->tail = node;
  }
  node->next = list->head;
  list->head = node;

  list->length++;
}

void llInsertLast(List* list, Node* node) {
  if (!list->head) {
    list->head = node;
  } else {
    list->tail->next = node;
  }

  list->tail = node;
  node->next = NULL;

  list->length++;
}

Node *llRemoveFirst(List* list) {
  if(!list->head) {
    return NULL;
  }

  Node* node = list->head;
  
  if (!node->next) {
    list->tail = NULL;
  }

  list->head = node->next;
  node->next = NULL;

  list->length--;

  return node;
}

void llInsertAfter(List *list, Node* node1, Node *node2) {
  Node *nodeAfter = node1->next;
  node1->next = node2;
  node2->next = nodeAfter;
  list->length++;
  if (list->tail == node1) { 
    list->tail = node2;
  }
}

Node *llRemoveAfter(List *list, Node* node) {
  Node *toRemove = node->next;
  if (list->tail == toRemove) {
    list->tail = node;
  }
  node->next = toRemove->next;
  toRemove->next = NULL;
  list->length--;
  return toRemove;
}

void llConcatenate(List* list1, List* list2) {
  if (!list1->head) {
    list1->head = list2->head;
  } else {
    list1->tail->next = list2->head;
  }

  if (list2->tail) {
    list1->tail = list2->tail;
  }

  // empty list 2
  list2->head = NULL;
  list2->tail = NULL;
  list1->length += list2->length;
  list2->length = 0;
}

Node* llHead(const List* list) {
  return list->head;
}

Node* llTail(const List* list) {
  return list->tail;
}

size_t llLength(const List* list) {
  return list->length;
}

Node* llNext(const Node* node) {
  return node->next;
}

int llKey(const Node* node) {
  return node->key;
}

void llFree(List* list) {
  free(list);
}

void llFreeAll(List* list) {
  Node* current = list->head;
  while(current) {
    Node* next = current->next;
    free(current);
    current = next;
  }
  llFree(list);
}

List* llCreateRandom(size_t length) {
  List *ll = llCreateEmpty();
  
  Node* head = NULL;

  for (size_t c = 0; c < length; ++c) {
    Node* newHead = createNode(head, rand() % length);
    if (!newHead) {
      ll->head = head;
      llFree(ll);
      return NULL;
    }
    if (head == NULL) {
      ll->tail = newHead;
    }
    head = newHead;
    ll->length++;
  }

  ll->head = head;

  return ll;
}

List* llCreateSorted(size_t length) {
  List *ll = llCreateEmpty();

  Node* head = NULL;
    
  for (size_t c = 0, i = length - 1; c < length; ++c, --i) {
    Node* newHead = createNode(head, i);
    if (!newHead) {
      ll->head = head;
      llFree(ll);      
      return NULL;
    }
    if (head == NULL) {
      ll->tail = newHead;
    }
    head = newHead;
    ll->length++;
  }

  ll->head = head;
  
  return ll;
}
