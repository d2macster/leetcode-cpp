//
// Created by Andrii Cherniak on 1/23/18.
//

#import <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> answer;
        int L = nums.size();
        if (L <= 1) {
            return nums;
        }
        int v1 = nums[0], v2, c1 = 1, c2 = 0, n;
        for (int i = 1; i < L; i++) {
            n = nums[i];
            if (c1 > 0 && n == v1) c1++;
            else if (c2 > 0 && n == v2) c2++;
            else if (c1 == 0) {
                v1 = n;
                c1 = 1;
            } else if (c2 == 0) {
                v2 = n;
                c2 = 1;
            }
            else {
                c1 = c1 > 0 ? c1 - 1 : 0;
                c2 = c2 > 0 ? c2 - 1 : 0;
            }
        }
        c1 = c2 = 0;
        for (int i = 0; i < L; i++){
            if (nums[i] == v1) c1++;
            else if (nums[i] == v2) c2++;
        }
        if (c1 > L/3) answer.push_back(v1);
        if (c2 > L/3) answer.push_back(v2);

        return answer;
    }
};