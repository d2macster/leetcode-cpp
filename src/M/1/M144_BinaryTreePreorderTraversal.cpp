//
// Created by Andrii Cherniak on 3/2/18.
//

#include <stack>
#include <vector>

using std::stack;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode * current = root;
        while (current || !s.empty()){
            if (current){
                result.push_back(current->val);
                s.push(current);
                current = current->left;
            }else{
                current = s.top();
                s.pop();
                current = current->right;
            }
        }
        return result;
    }
};