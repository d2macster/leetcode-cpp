//
// Created by Andrii Cherniak on 5/30/18.
//

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int L = A.size();
        if (L <= 1) return 0;
        long s = 0;
        for(int a: A) s += a;
        long F = 0;
        for(int i = 0; i < L; i++) F += i * A[i];
        long result = F;
        int aID = L - 1;
        for (int k = 1; k < L; k++) {
            F = F + s - L * A[aID];
            aID--;
            result = max(result, F);
        }
        return result;
    }
};