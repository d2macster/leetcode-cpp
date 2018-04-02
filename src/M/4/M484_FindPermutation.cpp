//
// Created by Andrii Cherniak on 4/2/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findPermutation(string s) {
        int Ls = s.size();
        if (Ls == 0)
            return vector<int>();
        vector<int> result = vector<int >(Ls+1, 0);
        for (int i = 0; i < Ls + 1; i++) result[i] = i + 1;
        for(int i = 0; i < Ls; i++){
            int j = i;
            while (j < Ls && s[j] == 'D')j++;
            reverse(result.begin()+i, result.begin()+j + 1);
            i = j;
        }
        return result;

    }
};