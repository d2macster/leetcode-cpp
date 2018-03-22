//
// Created by Andrii Cherniak on 3/22/18.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int L = s.size();
        int star = 0, cnt = 0;
        for (int i = 0; i < L; i++){
            if (s[i] == '(') cnt++;
            if (s[i] == '*') star++;
            if (s[i] == ')') {
                if (cnt > 0) cnt--;
                else if (star > 0) star--;
                else return false;
            }
        }
        star = cnt = 0;
        for (int i = L-1; i >=0; i--){
            if (s[i] == '*') star++;
            if (s[i] == ')') cnt++;
            if (s[i] == '('){
                if (cnt > 0) cnt--;
                else if (star > 0) star--;
                else return false;
            }
        }
        return true;
    }
};