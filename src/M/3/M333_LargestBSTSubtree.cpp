//
// Created by Andrii Cherniak on 3/8/18.
//
#include <tuple>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// min, max, cur_size, max_size
typedef std::tuple<int, int, int, int> i4tuple;

class Solution {
    i4tuple helper(TreeNode *n) {
        if (!n) return i4tuple(INT_MAX, INT_MIN, 0, 0);
        i4tuple l = helper(n->left);
        i4tuple r = helper(n->right);

        int min_l = get<0>(l), max_l = get<1>(l), size_l = get<2>(l), best_l = get<3>(l);
        int min_r = get<0>(r), max_r = get<1>(r), size_r = get<2>(r), best_r = get<3>(r);

        int min_v = std::min(min_l, n->val), max_v = std::max(n->val, max_r);
        int size_v = (max_l < n->val && n->val < min_r) ? 1 + size_l + size_r : INT_MIN;
        int best_size = std::max(size_v, std::max(best_l, best_r));

        return i4tuple(min_v, max_v, size_v, best_size);
    }

public:
    int largestBSTSubtree(TreeNode *root) {
        if (!root) return 0;
        i4tuple t = helper(root);

        return get<3>(t);
    }
};