//
// Created by Andrii Cherniak on 3/1/18.
//
#include <stack>

using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    stack<TreeNode *> ns;
public:
    BSTIterator(TreeNode *root) {
        TreeNode *curNode = root;
        while (curNode) {
            ns.push(curNode);
            curNode = curNode->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !ns.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *n = ns.top();
        ns.pop();
        TreeNode *n2 = n->right;
        while (n2){
            ns.push(n2);
            n2 = n2->left;
        }
        return n->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */