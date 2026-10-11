public class StackLinkedList {

    static class Node {
        int data;
        Node next;
        Node(int data) { this.data = data; }
    }

    private Node top;

    boolean isEmpty() { return top == null; }

    void push(int val) {
        Node n = new Node(val);
        n.next = top;
        top = n;
    }

    void pop() {
        if (isEmpty()) { System.out.println("Stack Underflow"); return; }
        System.out.println("Popped: " + top.data);
        top = top.next;
    }

    void peek() {
        if (isEmpty()) System.out.println("Stack is empty");
        else System.out.println("Top: " + top.data);
    }

    void display() {
        if (isEmpty()) { System.out.println("Stack is empty"); return; }
        System.out.print("Stack (top -> bottom): ");
        for (Node t = top; t != null; t = t.next) System.out.print(t.data + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        StackLinkedList s = new StackLinkedList();
        s.push(10); s.push(20); s.push(30);
        s.display();
        s.peek();
        s.pop();
        s.display();
    }
}
