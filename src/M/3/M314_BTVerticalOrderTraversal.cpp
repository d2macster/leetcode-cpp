//
// Created by Andrii Cherniak on 4/4/18.
//
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        map<int, vector<int>> order;
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            order[p.second].push_back(p.first->val);
            if (p.first->left)
                q.push(make_pair(p.first->left, p.second-1));
            if (p.first->right)
                q.push(make_pair(p.first->right, p.second+1));
        }
        for (auto it: order) result.push_back(it.second);
        return result;
    }
};