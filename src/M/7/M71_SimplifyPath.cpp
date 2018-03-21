//
// Created by Andrii Cherniak on 3/20/18.
//
#include <string>
#include <sstream>

using namespace std;

class Solution {
    void processDir(vector<string> &s, string &dir_name) {
        if (dir_name == "") return;
        if (dir_name == ".") {
            dir_name = "";
            return;
        }
        if (dir_name == "..") {
            if (!s.empty()) s.pop_back();
        } else s.push_back(dir_name);
        dir_name = "";
    }

public:
    string simplifyPath(string path) {
        vector<string> s;
        string dir_name = "", result = "";
        for (char c: path) {
            if (c == '/') {
                processDir(s, dir_name);
                dir_name = "";
            } else dir_name += c;
        }
        processDir(s, dir_name);

        for (auto p: s)
            result += "/" + p;
        return (s.empty()) ? "/" : result;
    }
};