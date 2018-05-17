//
// Created by Andrii Cherniak on 5/17/18.
//
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int L = A.size();
        if (L < 3) return 0;
        vector<int> diff = vector<int>(L-1, 0);
        for (int i = 0; i < L - 1; i++)
            diff[i] = A[i+1] - A[i];
        L--;
        int result = 0;
        for (int i = 0; i < L - 1; i++){
            for (int j = i + 1; j < L && diff[i] == diff[j]; j++) result++;
        }

        return result;
    }
};