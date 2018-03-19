//
// Created by Andrii Cherniak on 3/19/18.
//
#include <string>
#include <vector>

using namespace std;
struct Node {
public:
    vector<Node *> links = vector<Node *>(26, nullptr);
    int val = 0;

};

class MapSum {
    Node *root = new Node();
public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        if (key == "")
            return;
        Node *n = root;
        for (char ch: key) {
            if (n->links[ch - 'a'] == nullptr) n->links[ch - 'a'] = new Node();
            n = n->links[ch - 'a'];
        }
        n->val = val;
    }

    int sumHelper(string &prefix, int p_id, Node *next) {
        if (next == nullptr) return 0;
        if (p_id >= prefix.size()){
            int sum = 0;
            for (Node * n: next->links) sum += sumHelper(prefix, p_id + 1, n);
            sum += next->val;
            return sum;
        } else return sumHelper(prefix, p_id+1, next->links[prefix.at(p_id) - 'a']);
    }

    int sum(string prefix) {
        return sumHelper(prefix, 0, root);
    }
};
