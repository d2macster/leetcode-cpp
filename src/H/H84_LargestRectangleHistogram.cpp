//
// Created by Andrii Cherniak on 4/9/18.
//
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int L = heights.size();
        if (L == 0)
            return 0;
        stack<int> s = stack<int>();
        s.push(-1);
        int area = 0, idx;
        for (int i = 0; i < L; i++) {
            while (s.top() > -1 && heights[i] <= heights[idx = s.top()]){
                s.pop();
                area = max(area, heights[idx] * (i - s.top() - 1));
            }
            s.push(i);
        }

        while (s.top() > -1){
            idx = s.top();
            s.pop();
            area = max(area, heights[idx] * (L - s.top() - 1));
        }
        return area;
    }
};