//
// Created by Andrii Cherniak on 1/8/18.
//

#ifndef LEETCODE_E1_TWOSUM_H
#define LEETCODE_E1_TWOSUM_H

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


class E1_TwoSum {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result = vector<int>();

        unordered_map<int, int > numID;
        int diff = 0;
        int id = 0;
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
            diff = target - *i;
            if (numID.find(diff) != numID.end()){
                result.push_back(numID[diff]);
                result.push_back(id);
                return result;
            }

            numID[*i] = id;
            id ++;
        }
        return result;
    };
};


#endif //LEETCODE_E1_TWOSUM_H
