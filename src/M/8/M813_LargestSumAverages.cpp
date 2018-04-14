//
// Created by Andrii Cherniak on 4/13/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int> &A, int K) {
        if (K < 1)
            return 0;
        int L = A.size();
        vector<int > cusum = vector<int >(L+1, 0);
        for (int i = 0; i < L; i++)
            cusum[i+1] = cusum[i] + A[i];

        vector<double > dp = vector<double >(L, 0);
        for (int i = L-1; i >= 0; i--) dp[i] = 1.0*(cusum[L] - cusum[i])/(L-i);

        for (int k = 2; k <= K; k++){
            for (int i = 0; i < L; i++){
                for (int j = i + 1; j < L; j++ )
                    dp[i] = max(dp[i], 1.0*(cusum[j] - cusum[i])/ (j - i) + dp[j]);
            }
        }


        return dp[0];
    }
};