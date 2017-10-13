#include "doublyLinkedList.h"

struct node2LL* create_node2LL(int data) {
  struct node2LL* newNodePtr = (struct node2LL*) malloc(sizeof(struct node2LL));
  newNodePtr->data = data;
  newNodePtr->next = NULL;
  newNodePtr->previous = NULL;
  return newNodePtr;
}

void append_data2LL(struct node2LL** headPtrPtr, int data) {
  if (headPtrPtr==NULL) {
    return;
  }
  struct node2LL* newNode = create_node2LL(data);
  if (*headPtrPtr == NULL) {
    *headPtrPtr = newNode;
  } else {
    struct node2LL* current = *headPtrPtr;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
    newNode->previous = current;
  }
}

void print_list2LL(struct node2LL* headPtr) {
  struct node2LL* currentPtr = headPtr;
  int index = 0;
  while (currentPtr != NULL) {
    printf("{%d:%d} -> ",index,currentPtr->data);
    currentPtr = currentPtr -> next;
    index++;
  }
  printf("NULL\n");
}

void there_and_back_again2LL(struct node2LL* headPtr) {
  struct node2LL* currentPtr = headPtr;
  int index = 0;
  if (currentPtr != NULL) {
    printf("Walking through the list forwards\n");
    while (currentPtr->next != NULL) {
      printf("{%d:%d} -> ",index,currentPtr->data);
      currentPtr = currentPtr -> next;
      index++;
    }
    printf("{%d:%d} -> NULL\n",index,currentPtr->data);
    printf("Walking through the list backwards\n");
    printf("{%d:%d} -> ",index,currentPtr->data);
    while (currentPtr->previous != NULL) {
      currentPtr = currentPtr->previous;
      index--;
      printf("{%d:%d} -> ",index,currentPtr->data);
    }
    printf("NULL\n");
  } else {
    printf("List is NULL (forwards or backwards)\n");
  }
}


void delete_list2LL(struct node2LL** headPtrPtr) {
  if (headPtrPtr == NULL) {
    return;
  }
  struct node2LL* currentPtr = *headPtrPtr;
  struct node2LL* nextPtr = NULL;
  while (currentPtr != NULL) {
    nextPtr = currentPtr->next;
    currentPtr->next = NULL;
    currentPtr->previous = NULL;
    free(currentPtr);
    currentPtr = nextPtr;
  }
  *headPtrPtr = NULL;
}


//Deletes the FIRST node whose data matches the data param
void delete_node2LL(struct node2LL** headPtrPtr, int data) {
  assert(headPtrPtr != NULL);
  if (*headPtrPtr == NULL) {
    return;
  }
  if ((*headPtrPtr)->data == data) {
    struct node2LL* newHeadPtr = (*headPtrPtr)->next;
    if (newHeadPtr != NULL) {
      newHeadPtr->previous = NULL;
    }
    free(*headPtrPtr);
    *headPtrPtr = newHeadPtr;
  } else {
    struct node2LL* currentPtr = *headPtrPtr;
    while (currentPtr != NULL && currentPtr->data != data) {
      currentPtr = currentPtr->next;
    }
    if (currentPtr != NULL) {
      struct node2LL* prevPtr = currentPtr->previous;  
      struct node2LL* nextPtr = currentPtr->next;
      if (prevPtr != NULL) {
        prevPtr->next = nextPtr;
      }
      if (nextPtr != NULL) {
        nextPtr->previous = prevPtr;
      }
      free(currentPtr);
    }
  }
}
