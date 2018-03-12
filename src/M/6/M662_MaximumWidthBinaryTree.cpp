//
// Created by Andrii Cherniak on 3/11/18.
//

#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void dfs(TreeNode *n, int node_id, int level, vector<int> &min_v, vector<int> &max_v) {
        if (!n) return;
        if (min_v.size() < level) {
            min_v.push_back(node_id);
            max_v.push_back(node_id);
        } else {
            min_v[level - 1] = std::min(min_v[level - 1], node_id);
            max_v[level - 1] = std::max(max_v[level - 1], node_id);
        }
        dfs(n->left, 2 * node_id, level + 1, min_v, max_v);
        dfs(n->right, 2 * node_id + 1, level + 1, min_v, max_v);

    }

public:
    int widthOfBinaryTree(TreeNode *root) {
        if (!root)
            return 0;

        vector<int> min_v, max_v;
        dfs(root, 1, 1, min_v, max_v);
        int w = 0;
        for (int i = 0; i < min_v.size(); i++){
            w = std::max(w, max_v[i] - min_v[i] + 1);
        }
        return w;

    }
};