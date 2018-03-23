//
// Created by Andrii Cherniak on 3/23/18.
//
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct comparator{
    bool operator()(int l, int r){
        return l > r;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, comparator > q;
        for (int n: nums) {
            q.push(n);
            if (q.size() > k) q.pop();
        }
        return q.top();
    }
};