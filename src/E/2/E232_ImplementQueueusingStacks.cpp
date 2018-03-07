//
// Created by Andrii Cherniak on 3/7/18.
//
#include <stack>
using std::stack;

class MyQueue {
    stack<int > s_original, s_reverse;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s_original.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int v = peek();
        s_reverse.pop();
        return v;
    }

    /** Get the front element. */
    int peek() {
        if (s_reverse.empty()) {
            while (s_original.size()) {
                s_reverse.push(s_original.top());
                s_original.pop();
            }
        }
        return s_reverse.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s_original.empty() && s_reverse.empty();
    }
};
