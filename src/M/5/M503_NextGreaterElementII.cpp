//
// Created by Andrii Cherniak on 4/11/18.
//
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        stack<int> s;
        int L = nums.size();

        vector<int> GE = vector<int>(L, -1);
        for (int i = L - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i]) s.pop();
            GE[i] = (s.empty())? -1: s.top();
            s.push(nums[i]);

        }
        for (int i = L - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i]) s.pop();
            int v = (s.empty())? -1: s.top();
            if (GE[i] == -1) GE[i] = v;
            s.push(nums[i]);

        }
        return GE;
    }
};