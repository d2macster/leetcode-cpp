//
// Created by Andrii Cherniak on 1/15/18.
//

#include <vector>

using std::vector;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int L = nums.size();
        if (L == 0) return 0;
        int pProd = 0, nProd = 0;
        if (nums[0] > 0) pProd = nums[0];
        else nProd = nums[0];
        int m = nums[0];

        for (int i = 1; i < L; i++) {
            int n = nums[i];
            if (n < 0) std::swap(pProd, nProd);
            pProd = std::max(pProd * n, n);
            nProd = std::min(nProd * n, n);
            m = std::max(m, pProd);
        }

        return m;
    }
};