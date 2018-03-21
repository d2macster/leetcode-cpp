//
// Created by Andrii Cherniak on 3/21/18.
//
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {

public:
    string optimalDivision(vector<int> &nums) {
        ostringstream oss;
        oss << nums[0];
        int L = nums.size();
        if (L > 1)
            oss << "/";
        if (L > 2) oss << "(";
        for (int i = 1; i < L; i++) {
            if (i > 1) oss << "/";
            oss << nums[i];
        }
        if (L > 2) oss << ")";

        return oss.str();
    }
};