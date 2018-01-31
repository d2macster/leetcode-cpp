//
// Created by Andrii Cherniak on 1/31/18.
//
#include <vector>
#include <set>
using std::vector;
using std::set;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int > top3;
        for (const int n: nums) {
            top3.insert(n);
            if (top3.size() > 3) top3.erase(top3.begin());
        }
        return  (top3.size() == 3) ? *(top3.begin()) : *(--top3.end());
    }
};