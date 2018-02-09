//
// Created by Andrii Cherniak on 2/9/18.
//
#include <queue>

using std::queue;

class MovingAverage {
    queue<int> q;
    int w_size, cur_size = 0, sum = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        w_size = size;
    }

    double next(int val) {
        q.push(val);
        sum += val;
        cur_size++;
        if (cur_size > w_size) {
            cur_size--;
            sum -= q.front();
            q.pop();
        }
        return 1.0 * sum / cur_size;

    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */