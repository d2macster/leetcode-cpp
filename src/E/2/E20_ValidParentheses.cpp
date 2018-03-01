//
// Created by Andrii Cherniak on 3/1/18.
//
#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        int L = s.length();
        if (L % 2 == 1) return false;
        stack<char> p;
        for (char c: s) {
            if (p.empty()) p.push(c);
            else {
                char ch = p.top();
                if ((ch == '(' && c == ')') || (ch == '{' && c == '}') || (ch == '[' && c == ']')) p.pop();
                else p.push(c);
            }
        }
        return p.empty();
    }
};