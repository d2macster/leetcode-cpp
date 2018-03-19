//
// Created by Andrii Cherniak on 3/19/18.
//
#include <vector>

using namespace std;

struct TrieNode {
public:
    vector<TrieNode *> links = vector<TrieNode *>(26, nullptr);
    bool is_leaf = false;
};


class WordDictionary {
    TrieNode *root = new TrieNode();
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *n = root;
        for (char c: word) {
            if (n->links[c - 'a'] == nullptr) n->links[c - 'a'] = new TrieNode();
            n = n->links[c - 'a'];
        }
        n->is_leaf = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
    bool searchHelper(string &word, int c_id, TrieNode * next){
        if (next == nullptr)
            return false;
        int L = word.size();
        if (L == c_id) return next->is_leaf;
        if (word.at(c_id) != '.'){
            return searchHelper(word, c_id+1, next->links[word.at(c_id) - 'a']);
        }else{
            for (TrieNode * n: next->links)
                if (searchHelper(word, c_id+1, n)) return true;
        }
        return false;
    }
};
