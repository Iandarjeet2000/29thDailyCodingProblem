/* Implement a stack that has the following methods:

push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return null.
Each method should run in constant time. */


package DailyCodingProblem;

import java.util.*;
//import java.util.Stack;

class myStack {
    private Stack<Integer> st = new Stack<>();
    private Stack<Integer> maxSt = new Stack<>();

    public void push(int a) {

        if (maxSt.empty() || a > maxSt.peek()) {
            maxSt.push(a);
        }
        st.push(a);
    }

    public void pop() {
        if (maxSt.peek() == st.peek()) {
            maxSt.pop();
        }
        System.out.println(st.peek());
        st.pop();
    }

    public int getMax() {
        return maxSt.peek();
    }

};

public class DailyCodingProblem43 {

    public static void main(String args[]) {
        myStack s = new myStack();
        s.push(4);
        s.push(9);
        s.push(2);
        s.pop();
        System.out.println(s.getMax());

    }

}
