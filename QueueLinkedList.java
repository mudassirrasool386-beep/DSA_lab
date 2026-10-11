public class QueueLinkedList {

    static class Node {
        int data;
        Node next;
        Node(int data) { this.data = data; }
    }

    private Node front, rear;

    boolean isEmpty() { return front == null; }

    void enqueue(int val) {
        Node n = new Node(val);
        if (isEmpty()) front = rear = n;
        else { rear.next = n; rear = n; }
    }

    void dequeue() {
        if (isEmpty()) { System.out.println("Queue Underflow"); return; }
        System.out.println("Dequeued: " + front.data);
        front = front.next;
        if (front == null) rear = null;
    }

    void peek() {
        if (isEmpty()) System.out.println("Queue is empty");
        else System.out.println("Front: " + front.data);
    }

    void display() {
        if (isEmpty()) { System.out.println("Queue is empty"); return; }
        System.out.print("Queue (front -> rear): ");
        for (Node t = front; t != null; t = t.next) System.out.print(t.data + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        QueueLinkedList q = new QueueLinkedList();
        q.enqueue(10); q.enqueue(20); q.enqueue(30);
        q.display();
        q.peek();
        q.dequeue();
        q.display();
    }
}
