//
// Created by Andrii Cherniak on 4/9/18.
//
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty())
            return 0;
        stack<int> s;
        for (string &t: tokens) {
            if (t == "*") {
                int v1 = s.top();
                s.pop();
                int v2 = s.top();
                s.pop();
                s.push(v2 * v1);
            } else if (t == "+") {
                int v1 = s.top();
                s.pop();
                int v2 = s.top();
                s.pop();
                s.push(v2 + v1);
            } else if (t == "/") {
                int v1 = s.top();
                s.pop();
                int v2 = s.top();
                s.pop();
                s.push(v2 / v1);
            } else if (t == "-") {
                int v1 = s.top();
                s.pop();
                int v2 = s.top();
                s.pop();
                s.push(v2 - v1);
            } else
                s.push(stoi(t));
        }

        return s.top();
    }
};