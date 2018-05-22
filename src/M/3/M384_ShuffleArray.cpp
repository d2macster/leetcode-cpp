//
// Created by Andrii Cherniak on 5/22/18.
//
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
    vector<int> n, nn;
    int L = 0;
public:
    Solution(vector<int> nums) {
        n = nums;
        nn = n;
        L = nn.size();
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        nn = n;
        return nn;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (nn.size() <= 1)
            return nn;
        for (int i = 0; i < L; i++){
            swap(nn[i], nn[rand() % L]);
        }
        return nn;

    }
};