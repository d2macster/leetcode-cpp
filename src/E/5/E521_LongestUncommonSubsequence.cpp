//
// Created by Andrii Cherniak on 3/12/18.
//
#include <string>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        return (a == b)?-1:std::max(a.size(), b.size());
    }
};