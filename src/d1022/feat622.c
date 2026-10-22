#include<stdbool.h>
#include<stdlib.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int QueueSize;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj=malloc(sizeof(MyCircularQueue));
    obj->data=malloc((k+1)*sizeof(int));
    obj->front=0;
    obj->rear=0;
    obj->QueueSize=k+1;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if((obj->rear+1)%obj->QueueSize==obj->front)//这里可以调用后面的isFull一开始没想到，下同
        return false;
    obj->data[obj->rear]=value;
    obj->rear=(obj->rear+1)%obj->QueueSize;
    
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->front==obj->rear)
        return false;
    obj->front=(obj->front+1)%obj->QueueSize;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->front==obj->rear)
        return -1;
    return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->front==obj->rear)
        return -1;
    return obj->data[(obj->rear + obj->QueueSize - 1)% obj->QueueSize];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->front==obj->rear){
        return true;
    }else{
        return false;
    }
    
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if((obj->rear+1)%obj->QueueSize==obj->front){
        return true;
    }else{
        return false;
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}