//
// Created by Andrii Cherniak on 3/19/18.
//
#include <unordered_map>

using namespace std;

class Node {
    unordered_map<char, Node *> links;
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
            if (n->links.find(ch) != n->links.end()) n = n->links[ch];
            else {
                Node *nn = new Node(ch);
                n->links[ch] = nn;
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
            if (n->links.find(ch) == n->links.end()) return false;
            n = n->links[ch];
        }
        return n->exists;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix == "") return false;
        Node *n = root;
        for (char ch: prefix) {
            if (n->links.find(ch) == n->links.end()) return false;
            n = n->links[ch];
        }
        return n->exists || !n->links.empty();
    }
};