#include <vector>

class MyCircularQueue {
private:
    std::vector<int> data;
    int front;
    int rear;       
    int QueueSize; 

public:
    MyCircularQueue(int k)
        : data(k + 1), front(0), rear(0), QueueSize(k + 1) {}

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        data[rear] = value;
        rear = (rear + 1) % QueueSize;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % QueueSize;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return data[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return data[(rear + QueueSize - 1) % QueueSize];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % QueueSize == front;
    }
};
