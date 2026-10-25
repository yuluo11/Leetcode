class MyQueue {
private:
    int data[100];
    int top1;  // 入栈端，从数组左侧增长
    int top2;  // 出栈端，从数组右侧增长

public:
    MyQueue() : top1(-1), top2(100) {}

    void push(int x) {
        data[++top1] = x;
    }

    int pop() {
        if (top2 == 100) {
            while (top1 != -1) {
                data[--top2] = data[top1--];
            }
        }

        return data[top2++];
    }

    int peek() {
        if (top2 == 100) {
            while (top1 != -1) {
                data[--top2] = data[top1--];
            }
        }

        return data[top2];
    }

    bool empty() {
        return top1 == -1 && top2 == 100;
    }
};
