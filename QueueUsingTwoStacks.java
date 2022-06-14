/*Oues-53:-Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) data structure with the following methods: enqueue, which inserts an element into the queue, and dequeue, which removes it.

 */


import java.util.*;

public class QueueUsingTwoStacks {
    static class Queue {
        static Stack<Integer> s1 = new Stack<Integer>();
        static Stack<Integer> s2 = new Stack<Integer>();

        static void enQueue(int x) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());

            }

            s1.push(x);

            while (!s2.isEmpty()) {
                s1.push(s2.pop());

            }
        }

        static int deQueue() {
            if (s1.isEmpty()) {
                System.out.println("Q is Empty");
                System.exit(0);
            }

            int x = s1.peek();
            s1.pop();
            return x;
        }
    };

    // Driver code
    public static void main(String[] args) {
        Queue q = new Queue();
        q.enQueue(1);
        q.enQueue(2);
        q.enQueue(3);

        System.out.println(q.deQueue());
        System.out.println(q.deQueue());
        System.out.println(q.deQueue());
    }

}
