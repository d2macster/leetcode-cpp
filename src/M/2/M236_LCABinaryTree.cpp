#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct node_level {
    TreeNode *n;
    int level;
};

class Solution {
    vector<TreeNode *> dfs(TreeNode *root, TreeNode *target) {
        if (!root)
            return vector<TreeNode *>();
        stack<node_level> s;
        node_level l = {root, 1};
        s.push(l);
        vector<TreeNode *> result;
        vector<TreeNode *> path;

        while (!s.empty()) {
            node_level nl = s.top();
            s.pop();

            if (nl.level > path.size()) path.push_back(NULL);
            path[nl.level - 1] = nl.n;
            if (nl.n == target){
                for (int ll = 0; ll < nl.level; ll++) result.push_back(path[ll]);
                return result;
            }
            if (nl.n->left != NULL) {
                node_level left_l = {nl.n->left, nl.level + 1};
                s.push(left_l);
            }
            if (nl.n->right != NULL) {
                node_level right_l = {nl.n->right, nl.level + 1};
                s.push(right_l);
            }
        }

        return result;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return NULL;
        if (root == p || root == q) return root;
        vector<TreeNode *> p_path = dfs(root, p);
        vector<TreeNode *> q_path = dfs(root, q);

        TreeNode * lca = root;

        for (int i = 0; i < min(p_path.size(), q_path.size()) && p_path[i] == q_path[i]; i++) lca = p_path[i];

        return lca;
    }
};