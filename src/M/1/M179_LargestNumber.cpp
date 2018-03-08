//
// Created by Andrii Cherniak on 3/7/18.
//
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        string result = "";
        int L = nums.size();
        int nL = 0;
        vector<string> ns = vector<string>(L);

        for (int i = 0; i < L; i++)
            ns[i] = std::to_string(nums[i]);

        std::sort(ns.begin(), ns.end(), [](string &s1, string &s2) { return s1 + s2 < s2 + s1; });

        for (int i = L - 1; i >= 0; i--) {
            if (ns[i] != "0" || result != "")
            result = result + ns[i];
        }
        if (result == "") result = "0";
        return result;
    }
};