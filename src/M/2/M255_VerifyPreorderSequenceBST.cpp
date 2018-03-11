//
// Created by Andrii Cherniak on 3/11/18.
//
#include <vector>
#include <stack>
#include <limits>

using std::vector;
using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int> &preorder) {
        if (preorder.size() <= 1)
            return true;
        stack<int> s;
        int parent = INT_MIN;
        for (int v: preorder) {
            if (s.empty() || s.top() > v) {
                if (v < parent)
                    return false;
                s.push(v);
            }
            else {
                while (!s.empty() && s.top() < v) {
                    parent = s.top();
                    s.pop();
                }
                s.push(v);
            }
        }
        return true;
    }
};