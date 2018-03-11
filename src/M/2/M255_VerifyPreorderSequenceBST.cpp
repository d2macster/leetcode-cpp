//
// Created by Andrii Cherniak on 3/11/18.
//
#include <vector>
#include <iostream>

using std::vector;
using namespace std;

class Solution {
    bool check_helper(vector<int> &preorder, int l, int r) {
        if (r - l <= 0) return true;
        int root = preorder[l];
        int less_id = l;
        while (less_id + 1 <= r && preorder[less_id + 1] < root) less_id++;
        for (int i = less_id+1; i <= r; i++) if (preorder[i] < root) return false;

        if (!check_helper(preorder, l+1, less_id))
            return false;
        if (!check_helper(preorder, less_id + 1, r)) return false;
        return true;

    }

public:
    bool verifyPreorder(vector<int> &preorder) {
        int L = preorder.size();
        return check_helper(preorder, 0, L - 1);
    }
};