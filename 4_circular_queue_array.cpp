#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear, count;
public:
    CircularQueue() : front(0), rear(-1), count(0) {}

    bool isFull()  { return count == SIZE; }
    bool isEmpty() { return count == 0; }

    void enqueue(int val) {
        if (isFull()) { cout << "Queue Overflow\n"; return; }
        rear = (rear + 1) % SIZE;
        arr[rear] = val;
        count++;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow\n"; return; }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty\n";
        else cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Circular Queue: ";
        for (int i = 0, idx = front; i < count; i++, idx = (idx + 1) % SIZE)
            cout << arr[idx] << " ";
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    for (int i = 1; i <= 5; i++) q.enqueue(i * 10);
    q.display();
    q.enqueue(60);      // overflow
    q.dequeue();
    q.dequeue();
    q.enqueue(60);      // wraps around
    q.enqueue(70);      // wraps around
    q.display();
    q.peek();
    return 0;
}
