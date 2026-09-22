#include <stddef.h>
#include <stdlib.h>
typedef struct MyLinkedList {
    int val;
    struct MyLinkedList *next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj=malloc(sizeof(MyLinkedList));
    obj->next=NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    for(int i=0;i<index;i++){
        if(obj->next==NULL)
            return -1;
        obj=obj->next;
    }
    if (obj->next == NULL) {
    return -1;
    }
    return obj->next->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *temp=malloc(sizeof(MyLinkedList));
    temp->val=val;
    temp->next=obj->next;
    obj->next=temp;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* curr = obj;
    while(curr->next!=NULL)
        curr=curr->next;
    MyLinkedList *temp=malloc(sizeof(MyLinkedList));
    temp->val=val;
    curr->next=temp;
    temp->next=NULL;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *curr=obj;
    MyLinkedList *temp=malloc(sizeof(MyLinkedList));
    temp->val=val;
    int i=0;
    while(i<index &&curr->next!=NULL){
        curr=curr->next;
        i++;
    }
    if (i < index) {
        free(temp);
        return;
    }   
    temp->next = curr->next;
    curr->next = temp;   
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList *curr=obj;
    MyLinkedList *temp;
    int i=0;
    while(i<=index-1 &&curr->next!=NULL){
        curr=curr->next;
        i++; 
    }
    if(curr->next==NULL)
        return;
    temp=curr->next;
    curr->next=temp->next;
    free(temp);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *curr=obj->next;
    MyLinkedList *temp;
    while(curr){
        temp=curr->next;
        free(curr);
        curr=temp;
    }
    free(obj);
}
