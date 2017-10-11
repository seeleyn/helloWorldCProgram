#include "linkedList.h"


int get_length(struct node* head) {
  if (head == NULL) {
    return 0;
  }
  int length = 0;
  struct node* current = head;
  while (current != NULL) {
    current = current->next;
    length++;
  }
  return length;
}

struct node* get_nth(struct node* head, int n) {
  if (head == NULL || n<0) {
    return NULL;
  }
  int current_index = 0;
  struct node* current = head;
  while (current_index < n) {
    if (current == NULL) {
      return NULL;
    }
    current = current->next;
    current_index++;
  }
  return current;
}

void print_list(struct node* head) {
  struct node* current = head;
  int index = 0;
  while (current != NULL) {
    printf("{%d:%d} -> ",index,current->data);
    current = current -> next;
    index++;
  }
  printf("NULL\n");
}


void delete_list(struct node** headPtrPtr) {
  if (headPtrPtr == NULL) {
    return;
  }
  struct node* currentPtr = *headPtrPtr;
  struct node* nextPtr = NULL;
  while (currentPtr != NULL) {
    nextPtr = currentPtr->next;
    currentPtr->next = NULL;
    free(currentPtr);
    currentPtr = nextPtr;
  }
  *headPtrPtr = NULL;
}


void append_data(struct node** headRef, int data) {
  if (headRef==NULL) {
    return;
  }
  struct node* newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  if (*headRef == NULL) {
    *headRef = newNode;
  } else {
    struct node* current = *headRef;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

int pop(struct node** headPtrPtr) {
  if (headPtrPtr == NULL) {
    printf("Error: Cannot pop list because headPtrPtr is NULL\n");
    return 0;
  }
  struct node* headPtr = *headPtrPtr;
  if (headPtr == NULL) {
      printf("Error: Cannot pop list because list is empty\n");
      return 0;
  }
  struct node* newHeadPtr = headPtr->next;
  int data = headPtr->data;
  *headPtrPtr = newHeadPtr;
  headPtr->next = NULL;
  free(headPtr);
  return data;
}


struct node* create_node(int data) {
  struct node* newNodePtr = (struct node*) malloc(sizeof(struct node));
  newNodePtr->data = data;
  newNodePtr->next = NULL;
}


void insert_nth(struct node** headPtrPtr, int data, int n) {
  if (headPtrPtr == NULL) {
    printf("Error: headPtrPtr input parameter is NULL");
    return;
  }
  struct node* headPtr = *headPtrPtr;
  struct node* newNodePtr = create_node(data);


  if (headPtr==NULL) {
    if (n==0) {
      *headPtrPtr = newNodePtr;
    } else printf("Error: When adding to an empty list you can only add at n=0, not n=%d\n",data);
  } else {
    if (n==0) {
      newNodePtr->next = *headPtrPtr;
      *headPtrPtr = newNodePtr;
    } else {
      int index = 1;
      struct node* prevPtr = *headPtrPtr;
      struct node* currentPtr = (*headPtrPtr)->next;
      while (currentPtr != NULL && index < n) {
        prevPtr = currentPtr;
        currentPtr = currentPtr->next;
        index++;
      }
      if (index != n) {
        printf("Error: The list is to short to insert at index %d, list has only %d elements\n",n,index);
      } else {
        prevPtr->next = newNodePtr;
        newNodePtr->next = currentPtr;
      }
    }
  }
}



void sorted_insert(struct node** headPtrPtr, int data) {
  assert(headPtrPtr != NULL);  
  struct node* newNodePtr = create_node(data);
  if (*headPtrPtr == NULL) {
    *headPtrPtr = newNodePtr;
  } else if (newNodePtr->data < (*headPtrPtr)->data) {
    struct node* oldHead = *headPtrPtr;
    *headPtrPtr = newNodePtr;
    newNodePtr->next = oldHead;
  } else {
    struct node* previous = *headPtrPtr;
    struct node* current = (*headPtrPtr)->next;
    while (current != NULL && current->data <= newNodePtr->data) {
      previous = current;
      current = current->next;
    }
    previous->next = newNodePtr;
    newNodePtr->next = current;
  }
}



void front_back_split(struct node* sourcePtr, struct node** frontPtrPtr, struct node** backPtrPtr) {
  assert(frontPtrPtr != NULL);
  assert(backPtrPtr != NULL);

  if (sourcePtr == NULL) {
    *frontPtrPtr = NULL;
    *backPtrPtr = NULL;
  } else {
    *frontPtrPtr = sourcePtr;
    struct node* slowPtr = sourcePtr;
    struct node* fastPtr = sourcePtr;
    while (fastPtr->next != NULL && fastPtr->next->next != NULL) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;
    }
    *backPtrPtr = slowPtr->next;
    slowPtr->next = NULL; 
    sourcePtr = NULL;
  }
}



void remove_duplicates(struct node* sourcePtr) {
  if (sourcePtr == NULL) {
    return;
  }
  struct node* currentPtr = sourcePtr;
  while (currentPtr->next != NULL) {
    struct node* nextPtr = currentPtr->next;
    if (nextPtr->data == currentPtr->data) {
      currentPtr->next = nextPtr->next;
      free(nextPtr);   
    } else {
      currentPtr = currentPtr->next;
    }
  }
}

void move_node(struct node** sourcePtrPtr, struct node** destPtrPtr) {
  assert(sourcePtrPtr != NULL);
  assert(destPtrPtr != NULL);
  if (*sourcePtrPtr != NULL) {
    struct node* transferPtr = *sourcePtrPtr;
    *sourcePtrPtr = (*sourcePtrPtr)->next;
    transferPtr->next = *destPtrPtr;
    *destPtrPtr = transferPtr;
  }
}

struct node* copy_list(struct node* listPtr) {
  struct node* newHeadPtr;
  if (listPtr==NULL) {
    newHeadPtr = NULL;
  } else {
    newHeadPtr = create_node(listPtr->data);
    struct node* newListCurrentPtr = newHeadPtr;
    struct node* oldListCurrentPtr = listPtr->next;    
    while (oldListCurrentPtr != NULL) { 
      newListCurrentPtr->next = create_node(oldListCurrentPtr->data);
      newListCurrentPtr = newListCurrentPtr->next;
      oldListCurrentPtr = oldListCurrentPtr->next;
    }  
  } 
  return newHeadPtr;
}


struct node* sorted_merge(struct node* list1Ptr, struct node* list2Ptr) {
  if (list2Ptr == NULL) return copy_list(list1Ptr);
  if (list1Ptr == NULL) return copy_list(list2Ptr);
  struct node* aPtr = list1Ptr;
  struct node* bPtr = list2Ptr;
  struct node* headPtr = NULL;
  struct node* currentPtr = NULL;
  
  if (aPtr->data <= bPtr->data) {
    headPtr = create_node(aPtr->data);
    aPtr = aPtr->next; 
  } else {
    headPtr = create_node(bPtr->data);
    bPtr = bPtr->next;
  }
  currentPtr = headPtr;

  while (aPtr != NULL && bPtr != NULL) {
    int newData = 0;
    if (aPtr->data <= bPtr->data) {
      newData = aPtr->data;
      aPtr = aPtr->next;
    } else {
      newData = bPtr->data;
      bPtr = bPtr->next;
    }
    currentPtr->next = create_node(newData);
    currentPtr = currentPtr->next;
  }
  
  if (aPtr == NULL) {
    while (bPtr != NULL) {
      currentPtr->next = create_node(bPtr->data);
      currentPtr = currentPtr->next;
      bPtr = bPtr->next;
    }
  } else if (bPtr == NULL) {
    while (aPtr != NULL) {
      currentPtr->next = create_node(aPtr->data);
      currentPtr = currentPtr->next;
      aPtr = aPtr->next;
    }
  }
  return headPtr;
}



struct node* reverse(struct node* headPtr) {
  if (headPtr == NULL) {
    return;
  }
  struct node* prevPtr = NULL;
  struct node* currPtr = headPtr;
  struct node* nextPtr = NULL;
  while (currPtr != NULL) {
    nextPtr = currPtr->next;
    currPtr->next = prevPtr;
    prevPtr = currPtr;
    currPtr = nextPtr;
  }
  return prevPtr;
}

void append_second_list(struct node** aPtrPtr, struct node** bPtrPtr) {
  assert(aPtrPtr != NULL);
  assert(bPtrPtr != NULL);
 
  if (*aPtrPtr == NULL) {
    *aPtrPtr = *bPtrPtr;
    *bPtrPtr = NULL;
  } else {
    struct node* aPtr = *aPtrPtr;
    while (aPtr->next != NULL) {
      aPtr = aPtr->next;
    }
    aPtr->next = *bPtrPtr;
    *bPtrPtr = NULL;    
  }
}

