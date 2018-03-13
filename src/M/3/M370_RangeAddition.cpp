//
// Created by Andrii Cherniak on 3/12/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int> >& updates) {
        vector<int > result = vector<int >(length, 0);
        for (auto u: updates){
            int begin = u[0];
            int end = u[1];
            int increment = u[2];
            for (int i = begin; i <= end; i++) result[i] += increment;
        }
        return result;

    }
};