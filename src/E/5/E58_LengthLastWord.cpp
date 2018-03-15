//
// Created by Andrii Cherniak on 3/15/18.
//
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string ss = "";
        int result = 0;
        while (iss >> ss) result = ss.length();
        return result;

    }
};