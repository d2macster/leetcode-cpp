//
// Created by Andrii Cherniak on 1/9/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = nums[0];
        int counter = 1;
        for(int i = 1; i < nums.size(); ++i){
            if (nums[i] == el){
                counter ++;
            }else{
                counter --;
                if (counter == 0) {
                    el = nums[i];
                    counter = 1;
                }
            }
        }

        return el;

    }
};