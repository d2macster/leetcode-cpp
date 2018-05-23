//
// Created by Andrii Cherniak on 5/22/18.
//
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;
struct code_path {
    string code;
    int path_len;
};

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> visited;
        unordered_set<string> ends;
        for (string s: deadends) ends.insert(s);

        queue<code_path> q;
        code_path cp = {"0000", 0};
        q.push(cp);
        while (!q.empty()) {
                code_path c = q.front();
                q.pop();
                visited.insert(c.code);
                if (c.code == target) return c.path_len;
                if (ends.find(c.code) != ends.end()) continue;
                for (int i = 0; i <= 3; i++){
                        string next_c = c.code;
                        next_c[i] = '0' + (c.code[i] - '0' + 1) % 10;;
                        if (visited.find(next_c) == visited.end()){
                                code_path cp1 = {next_c, c.path_len + 1};
                                q.push(cp1);
                                visited.insert(next_c);
                        }
                        int v = c.code[i] - '0' - 1;
                        next_c[i] = '0' + ((v < 0)?(v + 10):v);
                        if (visited.find(next_c) == visited.end()){
                                code_path cp2 = {next_c, c.path_len + 1};
                                q.push(cp2);
                                visited.insert(next_c);
                        }
                }
        }

        return -1;
    }
};