//
// Created by Andrii Cherniak on 2/7/18.
//
#include <vector>
using std::vector;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int L = citations.size();
        int counter[L+1];
        for (int i = 0; i <= L; i++) counter[i] = 0;
        for (const int c :citations) counter[std::min(L, c)]++;

        int total = 0;
        for (int i = L; i >= 0; i--){
            total += counter[i];
            if (total >= i) return i;
        }


        return 0;
    }
};