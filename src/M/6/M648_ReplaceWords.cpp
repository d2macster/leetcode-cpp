//
// Created by Andrii Cherniak on 3/19/18.
//
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

struct Node {
    vector<Node *> links = vector<Node *>(26, nullptr);
    bool end = false;
    char ch;

    Node(char c) { ch = c; };
};

class Solution {
    Node *root = new Node((char) 0);

    void insertWord(string &word) {
        Node *n = root;
        for (char c: word) {
            if (n->links[c - 'a'] == nullptr) {
                Node *nn = new Node(c);
                n->links[c - 'a'] = nn;
            }
            n = n->links[c - 'a'];
        }
        n->end = true;
    }

    string replacement(string &word) {
        Node *n = root;
        int l = 0;
        for (char c: word) {
            if (n->links[c - 'a'] == nullptr) return word;
            n = n->links[c - 'a'];
            l++;
            if (n->end)
                return word.substr(0, l);
        }
        return word;
    }


public:
    string replaceWords(vector<string> &dict, string sentence) {
        if (sentence == "") return sentence;
        for (string &s: dict) insertWord(s);
        istringstream iss(sentence);
        ostringstream oss;
        string s;
        bool first = true;
        while (iss >> s) {
            if (!first) oss << " ";
            oss << replacement(s);
            first = false;
        }
        return oss.str();
    }
};