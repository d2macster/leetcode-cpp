//
// Created by Andrii Cherniak on 3/10/18.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    string getPreorder(TreeNode *root) {
        if (!root)
            return "";
        string left = getPreorder(root->left);
        string right = getPreorder(root->right);

        string result = to_string(root->val);
        if (left != "") result = result + "," + left;
        if (right != "") result = result + "," + right;
        return result;
    }

    string getInorder(TreeNode *root) {
        if (!root)
            return "";
        string left = getInorder(root->left);
        string right = getInorder(root->right);

        string result = "";

        if (left != "") result = result + left + ",";
        result = result + to_string(root->val);
        if (right != "") result = result + "," + right;
        return result;
    }

    unordered_map<int, int> m;

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int l, int r, int ll, int rr) {

        if (l > r || ll > rr) return nullptr;
        int root_val = preorder[l];
        int root_id = m[root_val];
        int inLeft = root_id - ll;

        TreeNode *root = new TreeNode(root_val);
        root->left = helper(preorder, inorder, l + 1, l + inLeft, ll, root_id - 1);
        root->right = helper(preorder, inorder, l + inLeft + 1, r, root_id + 1, rr);
        return root;
    }

    vector<int> getNumbers(string s) {
        int startIndex = 0, endIndex = 0;
        vector<int> result;
        while ((endIndex = s.find(',', startIndex)) < s.size()) {
            string ss = s.substr(startIndex, endIndex - startIndex);
            result.push_back(std::stoi(ss));
            startIndex = endIndex + 1;
        }
        if (startIndex < s.size()) {
            string ss = s.substr(startIndex);
            result.push_back(std::stoi(ss));
        }
        return result;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        return getPreorder(root) + ";" + getInorder(root);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int separator = data.find(';');
        string preorder_data = data.substr(0, separator);
        string inorder_data = data.substr(separator + 1);
        if (preorder_data == "" || inorder_data == "")
            return nullptr;
        vector<int> preorder = getNumbers(preorder_data);
        vector<int> inorder = getNumbers(inorder_data);

        for (int i = 0; i < inorder.size(); i++) m[inorder[i]] = i;


        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size() - 1);
    }
};
