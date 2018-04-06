//
// Created by Andrii Cherniak on 4/6/18.
//
#include <string>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        ostringstream oss;
        while (!q.empty()) {
            TreeNode *n = q.front();
            q.pop();
            if (n == NULL) oss << "null";
            else {
                oss << n->val;
                q.push(n->left);
                q.push(n->right);
            }
            oss << " ";
        }
        return oss.str();

    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        TreeNode *root = NULL;
        istringstream in(data);
        string nVal;
        vector<TreeNode *> prev_layer;
        vector<TreeNode *> cur_layer;
        while (in >> nVal) {
            TreeNode * n = NULL;
            if (nVal != "null"){
                n = new TreeNode(stoi(nVal));
            }
            if (!root) root = n;
            cur_layer.push_back(n);
            if (prev_layer.size() == 0 || cur_layer.size() == 2*prev_layer.size()){
                for(int i = 0; i < prev_layer.size(); i++){
                    prev_layer[i]->left = cur_layer[2*i];
                    prev_layer[i]->right = cur_layer[2*i+1];
                }
                prev_layer.clear();
                for(TreeNode * nn: cur_layer) if (nn) prev_layer.push_back(nn);
                cur_layer.clear();
            }
        }

        return root;
    }
};
