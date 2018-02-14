//
// Created by Andrii Cherniak on 1/10/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);

        for (int i = 1; i <= num; i++){
            if (i % 2 == 0) result[i] = result[i / 2];
            else result[i] = result[i-1] + 1;
        }

        return result;
    }
};