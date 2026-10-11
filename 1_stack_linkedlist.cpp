#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

class Stack {
    Node* top;
public:
    Stack() : top(nullptr) {}

    bool isEmpty() { return top == nullptr; }

    void push(int val) {
        Node* n = new Node(val);
        n->next = top;
        top = n;
    }

    void pop() {
        if (isEmpty()) { cout << "Stack Underflow\n"; return; }
        Node* temp = top;
        top = top->next;
        cout << "Popped: " << temp->data << endl;
        delete temp;
    }

    void peek() {
        if (isEmpty()) cout << "Stack is empty\n";
        else cout << "Top: " << top->data << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Stack is empty\n"; return; }
        cout << "Stack (top -> bottom): ";
        for (Node* t = top; t; t = t->next) cout << t->data << " ";
        cout << endl;
    }

    ~Stack() { while (!isEmpty()) { Node* t = top; top = top->next; delete t; } }
};

int main() {
    Stack s;
    s.push(10); s.push(20); s.push(30);
    s.display();
    s.peek();
    s.pop();
    s.display();
    return 0;
}
