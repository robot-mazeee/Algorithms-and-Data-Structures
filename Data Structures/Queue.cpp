#include <iostream>
using namespace std;

struct Queue{
    int front, rear, capacity;
    int *queue;

    Queue(int c) {
        front = 0;
        rear = -1;
        capacity = c;
        queue = new int[c];
    }

    ~Queue(){ delete[] queue; }

    bool isEmpty() { return front > rear; }

    void enqueue(int value) {
        if (rear == capacity-1) {
            cout << "\nQueue is full!\n";
            return;
        }
        queue[++rear] = value;
    }

    int dequeue() {
        if (this->isEmpty()) {
            cout << "\nQueue is empty!\n";
            return -1;
        }

        int value = queue[front];
        front = (front+1) % capacity;
        return value;
    }

    void getFront() {
        if (this->isEmpty()) {
            cout << "\nQueue is empty!\n";
            return;
        }

        cout << queue[front] << '\n';
    }

    void displayQueue() {
        if (this->isEmpty()) {
            cout << "\nQueue is empty!\n";
            return;
        }

        for (int i = front; i <= rear; i++) cout << queue[i] << " --> ";
        cout << '\n';
    }
};

int main() {
    Queue q = Queue(10);

    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(13);
    q.enqueue(2);
    q.enqueue(19);
    q.dequeue();
    q.getFront();
    q.displayQueue();

    return 0;
}