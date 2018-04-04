//
// Created by Andrii Cherniak on 4/4/18.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int L = nums.size();
        vector<long> sums = vector<long>(L, 0);
        long s = 0L;
        for (int i = 0; i < L; i++){
            s += nums[i];
            sums[i] = s;
        }
        unordered_map<long, int> observed;
        int counter = 0;
        for(int i = L-1; i >= 0; i--){
            long complement = sums[i] + k - nums[i];
            if (nums[i] == k) counter++;
            counter += observed[complement];
            observed[sums[i]]++;
        }

        return counter;
    }
};