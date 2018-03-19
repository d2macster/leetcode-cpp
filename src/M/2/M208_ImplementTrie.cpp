//
// Created by Andrii Cherniak on 3/19/18.
//
#include <vector>

using namespace std;

class Node {
    vector<Node *> links = vector<Node *>(26, nullptr);
    char c;
    bool exists = false;

    friend class Trie;

public:
    Node(char cc) {
        c = cc;
    }
};

class Trie {
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node((char) 0);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word == "")
            return;
        Node *n = root;
        for (char ch : word) {
            if (n->links[ch - 'a'] != nullptr) n = n->links[ch - 'a'];
            else {
                Node *nn = new Node(ch);
                n->links[ch - 'a'] = nn;
                n = nn;
            }
        }
        n->exists = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word == "") return false;
        Node *n = root;
        for (char ch : word) {
            n = n->links[ch - 'a'];
            if (n == nullptr) return false;
        }
        return n->exists;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix == "") return false;
        Node *n = root;
        for (char ch: prefix) {
            n = n->links[ch - 'a'];
            if (n == nullptr) return false;
        }
        for (Node *next: n->links)
            if (next != nullptr) return true;
        return n->exists;
    }
};