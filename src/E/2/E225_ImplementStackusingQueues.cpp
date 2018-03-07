//
// Created by Andrii Cherniak on 3/7/18.
//
#include <deque>

using std::deque;

class MyStack {
    deque<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int v = q.back();
        q.pop_back();
        return v;
    }

    /** Get the top element. */
    int top() {
        return q.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};