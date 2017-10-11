#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct node2LL {
  int data;
  struct node2LL* next;
  struct node2LL* previous;
};

void print_list2LL(struct node2LL* head);

void delete_list2LL(struct node2LL** headPtrPtr);

void append_data2LL(struct node2LL** headRef, int data);

struct node2LL* create_node2LL(int data);

void there_and_back_again2LL(struct node2LL* headPtr);

#endif
