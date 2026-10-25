#include<stdbool.h>
typedef struct {
    int data[100];
    int top1;
    int top2;
} MyQueue;


 MyQueue* myQueueCreate() {
    MyQueue *obj=malloc(sizeof(MyQueue));
    obj->top1=-1;
    obj->top2=100;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->data[++obj->top1]=x;
}

int myQueuePop(MyQueue* obj) {
    if(obj->top2==100){
        while(obj->top1!=-1){
            obj->data[--obj->top2]=obj->data[obj->top1--];
        }
    }
    return obj->data[obj->top2++]; 
}

int myQueuePeek(MyQueue* obj) {
    if(obj->top2==100){
        while(obj->top1!=-1){
            obj->data[--obj->top2]=obj->data[obj->top1--];
        }
    }
    return obj->data[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->top1==-1 && obj->top2==100){
        return true;
    }else{
        return false;
    }
            
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
