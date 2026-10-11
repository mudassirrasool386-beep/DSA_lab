public class CircularQueueArray {

    private final int SIZE = 5;
    private int[] arr = new int[SIZE];
    private int front = 0, rear = -1, count = 0;

    boolean isFull()  { return count == SIZE; }
    boolean isEmpty() { return count == 0; }

    void enqueue(int val) {
        if (isFull()) { System.out.println("Queue Overflow"); return; }
        rear = (rear + 1) % SIZE;
        arr[rear] = val;
        count++;
    }

    void dequeue() {
        if (isEmpty()) { System.out.println("Queue Underflow"); return; }
        System.out.println("Dequeued: " + arr[front]);
        front = (front + 1) % SIZE;
        count--;
    }

    void peek() {
        if (isEmpty()) System.out.println("Queue is empty");
        else System.out.println("Front: " + arr[front]);
    }

    void display() {
        if (isEmpty()) { System.out.println("Queue is empty"); return; }
        System.out.print("Circular Queue: ");
        int idx = front;
        for (int i = 0; i < count; i++) {
            System.out.print(arr[idx] + " ");
            idx = (idx + 1) % SIZE;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        CircularQueueArray q = new CircularQueueArray();
        for (int i = 1; i <= 5; i++) q.enqueue(i * 10);
        q.display();
        q.enqueue(60);   // overflow
        q.dequeue();
        q.dequeue();
        q.enqueue(60);   // wrap around
        q.enqueue(70);   // wrap around
        q.display();
        q.peek();
    }
}
