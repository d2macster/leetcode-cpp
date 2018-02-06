//
// Created by Andrii Cherniak on 2/5/18.
//
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
    int findLHS(vector<int> &nums) {
        map<int, int> counter;
        for (int n: nums) counter[n]++;
        int answer = 0;
        for (auto c: counter)
            if (counter[c.first - 1] > 0)
            answer = std::max(answer, c.second + counter[c.first - 1]);

        return answer;
    }
};