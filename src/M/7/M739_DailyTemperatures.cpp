//
// Created by Andrii Cherniak on 2/7/18.
//
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int L = temperatures.size();
        vector<int> answer = vector<int>(L, 0);
        map<int, int> m;
        map<int, int>::iterator it;
        int w_id;
        for (int i = L - 1; i >= 0; i--) {
            w_id = L;
            m[temperatures[i]] = i;

            for (it = ++m.find(temperatures[i]); it != m.end(); it++)
                w_id = std::min(w_id, it->second);

            answer[i] = (w_id == L)? 0: w_id - i;

        }

        return answer;
    }
};