//
// Created by Andrii Cherniak on 1/11/18.
//

#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        int L = words.size();
        if (L == 0)
            return 0;
        unsigned int cache[L];
        unsigned int wl[L];
        for (int i = 0; i < L; i++){
            int mask = 0;
            for(char ch: words[i]) mask |= 1 << (ch - 'a');
            cache[i] = mask;
            wl[i] = words[i].size();
        }

        for (int i = 0; i < L; i++){
            for (int j = i; j < L; j++){
                if ((cache[i] & cache[j]) == 0) {
                    int p = wl[i]*wl[j];
                    result = (result < p)?p:result;
                }
            }
        }
        return result;
    }
};