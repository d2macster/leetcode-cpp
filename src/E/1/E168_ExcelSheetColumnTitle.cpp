//
// Created by Andrii Cherniak on 4/29/18.
//
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string title = "";
        while (n > 0) {
            int r = (n - 1) % 26;
            char c = 'A' + r;
            title += c;
            n = (n - r - 1) / 26;
        }
        reverse(title.begin(), title.end());
        return title;
    }
};