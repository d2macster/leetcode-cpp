//
// Created by Andrii Cherniak on 4/14/18.
//
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "") return false;
        vector<string> tree;
        for (char c: preorder)
            if (('0' <= c && c <= '9') || (c == '#') || (c == ',')) {}
            else
                return false;

        replace(preorder.begin(), preorder.end(), ',', ' ');
        istringstream in(preorder);
        string v;
        while (in >> v) {
//            cout << v << endl;
            tree.push_back(v);
            while (tree.size() >= 3 && tree[tree.size()-3] != "#" && tree[tree.size()-2] == "#" && tree[tree.size()-1] == "#"){
                tree.pop_back();
                tree.pop_back();
                tree.pop_back();
                tree.push_back("#");
            }
//            for (string & s: tree) cout << s << " ";
//            cout << endl;
        }
        return tree.empty() || (tree.size() == 1 && tree[0] == "#");
    }
};