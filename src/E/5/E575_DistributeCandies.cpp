//
// Created by Andrii Cherniak on 2/5/18.
//
#include <vector>
#include <string>
#include <unordered_set>
using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int L = candies.size();
        unordered_set<int> s = unordered_set<int>(L);
        for (const int c : candies) s.insert(c);
        return std::min(L/2, int(s.size()));
    }
};