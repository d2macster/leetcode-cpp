//
// Created by Andrii Cherniak on 3/22/18.
//
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        stack<vector<int>> s;
        vector<int> result = vector<int >(n, 0);
        int timer = 0;
        for (string &log: logs) {
            replace(log.begin(), log.end(), ':', ' ');
            istringstream in(log);
            int p_id, ts;
            string action;
            in >> p_id;
            in >> action;
            in >> ts;
            vector<int> log_p = vector<int>(3,0);
            log_p[0] = p_id;
            log_p[1] = (action == "start")?1:0;
            log_p[2] = ts;

            if (s.empty()) {
                s.push(log_p);
                timer = ts;
            }
            else{
                vector<int> log_pp = s.top();
                if (log_p[1] == 1){
                    result[log_pp[0]] += ts - timer;
                    s.push(log_p);
                    timer = ts;
                }else{
                    s.pop();
                    result[p_id] += ts - timer + 1;
                    timer = ts + 1;
                }
            }
        }
        return result;
    }
};