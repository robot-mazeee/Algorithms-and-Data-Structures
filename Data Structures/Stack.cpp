#include <iostream>
using std::cout;

#define MAX 100

struct Stack {
    int top;
    int stack[MAX];

    Stack() { top = -1; }

    bool isEmpty() { return top < 0; }

    void push(int value) {
        if (top >= MAX-1) {
            cout << "\nStack overflow\n";
            return;
        }
        stack[++top] = value;
    }

    int pop() {
        if (this->isEmpty()) {
            cout << "\nStack is empty!\n";
            return 0;
        }
        int value = stack[top--];
        return value;
    }

    int peek() {
        if (this->isEmpty()) {
            cout << "\nStack is empty!\n";
            return 0;
        }
        int value = stack[top];
        return value;
    }

    void displayStack() {
        for (int i = 0; i <= top; i++) cout << stack[i] << '\n'; 
    }
};

int main() {
    Stack s = Stack();

    s.push(10);
    s.push(11);
    s.push(20);
    s.push(13);
    s.push(21);
    s.pop();
    cout << s.peek() << '\n';
    s.displayStack();

    return 0;
}