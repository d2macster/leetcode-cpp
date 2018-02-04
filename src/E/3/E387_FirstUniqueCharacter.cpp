//
// Created by Andrii Cherniak on 2/3/18.
//
#include <string>
using std::string;

class Solution {
public:
    int firstUniqChar(string s) {
        int L = s.length();
        int hash[255][2];
        for (int i = 0; i < 255; i++) {
            hash[i][0] = 0;
            hash[i][1] = L;
        }
        for (int i = 0; i < L; i++){
            hash[s[i]][0] ++;
            hash[s[i]][1] = (hash[s[i]][0] == 1) ? i : hash[s[i]][1];
        }
        int answer = L;
        for (int i = 0; i < 255; i++)
            answer = (hash[i][0] == 1 && hash[i][1] < answer)? hash[i][1] : answer;

        return (answer != L)? answer : -1;

    }
};