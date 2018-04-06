//
// Created by Andrii Cherniak on 4/6/18.
//
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct cmpMin{
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};
struct cmpMax{
    bool operator()(int v1, int v2){
        return v1 < v2;
    }
};

class MedianFinder {
    priority_queue<int, vector<int>, cmpMin> min_heap;
    priority_queue<int, vector<int>, cmpMax> max_heap;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        max_heap.push(num);
        while (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        while (!min_heap.empty() && !max_heap.empty() && min_heap.top() < max_heap.top()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        int L = max_heap.size() + min_heap.size();
        int max_heap_target = (L % 2 == 0)?L/2:L/2+1;
        while (max_heap.size() < max_heap_target){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        while (max_heap.size() > max_heap_target){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double findMedian() {
        int L = max_heap.size() + min_heap.size();
        return (L % 2 == 0)?0.5*(max_heap.top() + min_heap.top()):max_heap.top();
    }
};