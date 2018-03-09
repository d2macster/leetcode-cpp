//
// Created by Andrii Cherniak on 3/8/18.
//
#include <vector>
#include <unordered_map>
#include <queue>

using std::vector;
using std::unordered_map;
using std::queue;

class Solution {
public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        vector<int> result;
        queue<int> q;
        unordered_map<int, vector<int> > m;
        int L = pid.size();
        for (int i = 0; i < L; i++)
            m[ppid[i]].push_back(pid[i]);

        q.push(kill);

        while (!q.empty()) {
            int p = q.front();
            q.pop();
            result.push_back(p);
            for (int pp: m[p]) q.push(pp);
        }

        return result;
    }
};