//
// Created by Andrii Cherniak on 4/4/18.
//
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int La = A.size();
        int Lb = B.size();

        vector<vector<int >> dp = vector<vector<int >>(La+1, vector<int >(Lb+1, 0));

        int maxL = 0;
        for (int i = 1; i <= La; i++)
            for (int j = 1; j <= Lb; j++){
                int check = (A[i-1] == B[j-1]);
                dp[i][j] = check*(dp[i-1][j-1] + check);
                maxL = max(maxL, dp[i][j]);
            }

        return maxL;
    }
};