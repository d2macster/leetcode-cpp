//
// Created by Andrii Cherniak on 3/12/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int> > &updates) {
        vector<int> result = vector<int>(length, 0);
        for (auto u: updates) {
            int begin = u[0];
            int end = u[1];
            int increment = u[2];
            result[begin] += increment;
            if (end + 1 < length)
                result[end + 1] -= increment;
        }
        int cummulative = 0;
        for (int i = 0; i < length; i++) {
            cummulative += result[i];
            result[i] = cummulative;
        }
        return result;
    }
};