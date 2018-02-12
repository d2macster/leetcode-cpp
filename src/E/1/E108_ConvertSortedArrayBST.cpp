//
// Created by Andrii Cherniak on 2/12/18.
//

#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode * helper(vector<int> &nums, int l, int r){
        if (l > r)
            return NULL;

        int mid = (r - l) / 2 + l;
        TreeNode * n = new TreeNode(nums[mid]);
        n->left = helper(nums, l, mid - 1);
        n->right = helper(nums, mid + 1, r);
        return n;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        int L = nums.size();
        return helper(nums, 0, L-1);
    }
};