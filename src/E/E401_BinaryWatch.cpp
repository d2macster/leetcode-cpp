//
// Created by Andrii Cherniak on 1/10/18.
//
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int cache[60];

        for (int i = 0; i <= 59; i++) {
            cache[i] = __builtin_popcount(i);
        }
        vector<string> result = vector<string>();
        for (int h = 0; h <= 11; h++) {
            for (int m = 0; m <= 59; m++) {
                if (cache[h] + cache[m] == num){
                    stringstream time;
                    time << h << ":";
                    if (m < 10) time << "0";
                    time << m;
                    result.push_back(time.str());
                }
            }
        }
        return result;
    }
};