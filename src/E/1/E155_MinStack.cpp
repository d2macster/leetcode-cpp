//
// Created by Andrii Cherniak on 3/1/18.
//
#include <stack>
#include <limits>

using std::stack;

class MinStack {
    stack<int> s, m;
    int min_v = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        s.push(x);
        min_v = std::min(min_v, x);
        m.push(min_v);
    }

    void pop() {
        s.pop();
        m.pop();
        min_v = (!m.empty())? m.top() : INT_MAX;
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */