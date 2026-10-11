#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

class Queue {
    Node *front, *rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() { return front == nullptr; }

    void enqueue(int val) {
        Node* n = new Node(val);
        if (isEmpty()) front = rear = n;
        else { rear->next = n; rear = n; }
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow\n"; return; }
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty\n";
        else cout << "Front: " << front->data << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Queue (front -> rear): ";
        for (Node* t = front; t; t = t->next) cout << t->data << " ";
        cout << endl;
    }

    ~Queue() { while (!isEmpty()) { Node* t = front; front = front->next; delete t; } }
};

int main() {
    Queue q;
    q.enqueue(10); q.enqueue(20); q.enqueue(30);
    q.display();
    q.peek();
    q.dequeue();
    q.display();
    return 0;
}
