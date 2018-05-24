//
// Created by Andrii Cherniak on 5/24/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int L = nums.size();
        vector<int> lengths = vector<int>(L, 0);
        vector<int> counts = vector<int>(L, 0);

        for (int i = L-1; i >= 0; i--){
            lengths[i] = 1;
            counts[i] = 1;
            for (int j = i + 1; j < L; j++){
                if (nums[j] > nums[i]){
                    if (lengths[j] + 1 == lengths[i]){
                        counts[i]+= counts[j];
                    }
                    if (lengths[j] + 1 > lengths[i]){
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                    }
                }
            }
        }

        int lis_v = 0;
        int lis_c = 0;

        for (int i = 0; i < L; i++){
            if (lengths[i] > lis_v){
                lis_v = lengths[i];
                lis_c = counts[i];
            }
            else if (lengths[i] == lis_v) lis_c += counts[i];
        }


        return lis_c;
    }
};