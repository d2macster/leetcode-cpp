//
// Created by Andrii Cherniak on 1/31/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int L = nums.size();
        if (L == 0 || k == 0 || L < k) return 0;
        long s = 0, answer = 0;
        int counter = 0;
        for (int i = 0; i < L; i++) {
            s += nums[i];
            counter++;
            if (counter > k) {
                counter--;
                s -= nums[i - k];
                answer = std::max(answer, s);
            } else
                answer = s;
        }
        return 1.0*answer / k;
    }
};