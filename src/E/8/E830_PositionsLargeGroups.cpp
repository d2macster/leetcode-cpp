//
// Created by Andrii Cherniak on 5/18/18.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        int L = S.size();
        char pre = (char) 0;
        int begin = 0, end = 0;
        for (int i = 0; i < L; i++){
            if (S[i] == pre) end = i;
            else {
                if (end - begin >= 2){
                    vector<int> p = vector<int >(2, 0);
                    p[0] = begin;
                    p[1] = end;
                    result.push_back(p);
                }
                begin = end = i;
            }
            pre = S[i];
        }
        if (end - begin >= 2){
            vector<int> p = vector<int >(2, 0);
            p[0] = begin;
            p[1] = end;
            result.push_back(p);
        }
        return result;
    }
};