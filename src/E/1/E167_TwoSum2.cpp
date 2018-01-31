//
// Created by Andrii Cherniak on 1/18/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer = vector<int>(2, 0);
        int L = numbers.size();
        int lo = 0;
        int hi = L-1;
        int sum;
        while (lo < hi){
            sum = numbers[lo] + numbers[hi];
            if (target > sum) lo++;
            else if (target < sum) hi --;
            else{
                answer[0] = lo + 1;
                answer[1] = hi + 1;
                return answer;
            }
        }
        return answer;
    }
};