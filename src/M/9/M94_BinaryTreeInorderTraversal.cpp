//
// Created by Andrii Cherniak on 3/1/18.
//
#include <vector>
#include <stack>

using std::vector;
using std::stack;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root)
            return result;
        stack<TreeNode *> toVisit;
        TreeNode * curNode = root;
        while (curNode || !toVisit.empty()){
            if (curNode){
                toVisit.push(curNode);
                curNode = curNode->left;
            }else{
                curNode = toVisit.top();
                result.push_back(curNode->val);
                toVisit.pop();
                curNode = curNode->right;
            }
        }
        return result;
    }
};