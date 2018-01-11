//
// Created by Andrii Cherniak on 1/10/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        int cache[num + 1];
        cache[0] = 0;
        result.push_back(cache[0]);

        int upper = 1;
        int lower_mask = 0;

        for (int i = 1; i <= num; i++){
            if (i > upper){
                upper <<= 1;
                lower_mask = (upper - 1) >> 1;
            }
            cache[i] = 1 + cache[i & lower_mask];
            result.push_back(cache[i]);
        }

        return result;
    }
};