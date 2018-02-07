//
// Created by Andrii Cherniak on 2/7/18.
//
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int L = temperatures.size();
        vector<int> answer = vector<int>(L, 0);
        unordered_map<int, int> m(L);
        int w_id;
        for (int i = L - 1; i >= 0; i--) {
            w_id = L;
            for (int t = temperatures[i] + 1; t <= 100; t++)
                if (m.find(t) != m.end()) w_id = std::min(w_id, m[t]);
            answer[i] = (w_id == L)? 0: w_id - i;

            m[temperatures[i]] = i;
        }

        return answer;
    }
};