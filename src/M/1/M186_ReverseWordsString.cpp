//
// Created by Andrii Cherniak on 3/21/18.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(vector<char> &str) {
        reverse(str.begin(), str.end());
        int L = str.size();
        int begin = -1;
        for(int i = 0; i < L; i++){
            if (str[i] != ' ' && begin == -1) begin = i;
            if (str[i] == ' ' && begin != -1){
                reverse(str.begin() + begin, str.begin()+i);
                begin = -1;
            }
        }
        if (begin != -1) reverse(str.begin() + begin, str.end());
    }
};