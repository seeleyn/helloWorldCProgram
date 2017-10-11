#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <assert.h>

struct node {
  int data;
  struct node* next;
};

int get_length(struct node* head);

struct node* get_nth(struct node* head, int n);

void print_list(struct node* head);

void delete_list(struct node** headPtrPtr);

void append_data(struct node** headRef, int data);

int pop(struct node** headPtrPtr);

struct node* create_node(int data);

void insert_nth(struct node** headPtrPtr, int data, int n);

void sorted_insert(struct node** headPtrPtr, int data);

void front_back_split(struct node* sourcePtr, struct node** frontPtrPtr, struct node** backPtrPtr);

void remove_duplicates(struct node* sourcePtr);

void move_node(struct node** sourcePtrPtr, struct node** destPtrPtr);

struct node* copy_list(struct node* listPtr);

struct node* sorted_merge(struct node* list1Ptr, struct node* list2Ptr);

struct node* reverse(struct node* headPtr);

void append_second_list(struct node** aPtrPtr, struct node** bPtrPtr);

#endif
