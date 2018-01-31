//
// Created by Andrii Cherniak on 1/18/18.
//
#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int L = nums.size();
        if (L <= 1) return;
        k %= L;
        if (k == 0) return;
        int count = 0;

        for (int start = 0; count < L; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % L;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }

    }
};