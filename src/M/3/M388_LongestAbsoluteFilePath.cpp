//
// Created by Andrii Cherniak on 4/9/18.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int > counter = vector<int >(300, 0);
        int pathLen = 0;
        for (int i = 0, level = 0, isFile = 0, len = 0, acc = 0; i < input.size(); i++){
            switch (input[i]){
                case '\n' : level = 0; isFile = 0; len = 0;
                    break;
                case '\t' : level ++;
                    break;
                case '.': isFile = 1;
                default:
                    len++;
                    counter[level] = len;
                    if (isFile) {
                        acc = 0;
                        for (int l = 0; l <= level; l++)
                            acc += counter[l];
                        pathLen = max(pathLen, acc + level);
                    }

            }
        }
        return pathLen;
    }
};