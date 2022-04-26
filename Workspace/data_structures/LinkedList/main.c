#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    int key;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

void printList(void){
    struct Node *ptr = head;
    
    printf("\n[ ");
    
    while(ptr != NULL){
        printf("(%d,%d)", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    
    printf(" ]");
    
    
//    for (; current;current=current->next) {
//        printf("%d",current->data);
//    }
}

void insertFirst(int key, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->key = key;
    ptr->data = data;
    ptr->next = head;
    head = ptr;
}

struct Node *delfirst(void) {
    if(!head)
        return NULL;
    struct Node *ptr = head;
    head = head->next;
    return (ptr);
}

bool isEmpty(void) {
    return head == NULL;
}

int length(void) {
    int length = 0;
    struct Node *ptr = head;
    while (ptr) {
        length++;
        ptr = ptr->next;
    }
    return (length);
}

struct Node *find(int key) {
    struct Node *ret = head;
    while(ret->key != key && ret) {
        ret = ret->next;
    }
    return (ret);
}

//ODEV
struct Node *delete(int key) {
    if(!head)
        return NULL;
    struct Node *ptr = head;
    while(ptr->next) {
        if (ptr->next->key == key) {
            struct Node *a = ptr->next;
            ptr->next = ptr->next->next;
            return a;
        }
        else
            ptr = ptr->next;
    }
    return (NULL);
}

//struct Node *delete(int key) {
//    if(!head)
//            return NULL;
//        struct Node *ptr = head;
//        struct Node *prev = NULL;
//        while(ptr->key != key && ptr) {
//            prev = ptr;
//            ptr = ptr->next;
//        }
//        if (ptr->key == key)
//        {
//            prev->next = ptr->next;
//            ptr = NULL;
//    }
//    return ptr;
//}

//ODEV BUBBLE
void    swap(struct Node *a, struct Node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void sort(void){
    struct Node *ptr;
    struct Node *ptrl = NULL;
    bool swape;

    do
    {
        ptr = head;
        swape = false;
        while (ptr->next != ptrl) {
            if (ptr->data < ptr->next->data) {
                swape = true;
                swap(ptr, ptr->next);
            }
            ptr = ptr->next;
        }
        ptrl = ptr;
    }
    while(swape);
}

//Sort quick;
//void sortQ(void){
//
//}


//reverse
void reverse(struct Node **head_ref) {
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next;
        
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
    *head_ref = prev;
}





