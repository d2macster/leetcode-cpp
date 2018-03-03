//
// Created by Andrii Cherniak on 3/2/18.
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
    TreeNode *helper(vector<int> &nums, int lo, int hi) {
        if (lo > hi) return NULL;
        int max_id = lo;
        int max_v = nums[lo];
        for (int i = lo; i <= hi; i++){
            if (nums[i] > max_v){
                max_v = nums[i];
                max_id = i;
            }
        }
        TreeNode * n = new TreeNode(max_v);
        n->left = helper(nums, lo, max_id - 1);
        n->right = helper(nums, max_id + 1, hi);
        return n;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        int L = nums.size();
        return helper(nums, 0, L - 1);
    }
};