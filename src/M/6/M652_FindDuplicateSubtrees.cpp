//
// Created by Andrii Cherniak on 3/11/18.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_set<string> s, in_duplicates;

    string dfs(TreeNode *n, vector<TreeNode *> &duplicates) {
        if (!n) return "";
        string signature = to_string(n->val) + "," + dfs(n->left, duplicates) + "," + dfs(n->right, duplicates);
        if (s.find(signature) != s.end() && in_duplicates.find(signature) == in_duplicates.end()){
            duplicates.push_back(n);
            in_duplicates.insert(signature);
        }
        s.insert(signature);
        return signature;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        vector<TreeNode *> duplicates;
        dfs(root, duplicates);
        return duplicates;
    }
};