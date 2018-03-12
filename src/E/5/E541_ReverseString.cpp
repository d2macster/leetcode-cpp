//
// Created by Andrii Cherniak on 3/12/18.
//
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int L = s.size();
        for (int begin = 0; begin < L; begin += 2*k){
            int end = std::min(begin + k, L);
            reverse(s.begin()+begin, s.begin()+end);
        }
        return s;
    }
};