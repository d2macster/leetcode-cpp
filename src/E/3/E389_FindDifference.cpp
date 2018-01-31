//
// Created by Andrii Cherniak on 1/10/18.
//

#include <string>
using std::string;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unsigned int buffer = 0;
        int i = 0;
        for (int i = 0; i < s.size(); i++){
            buffer ^= s.at(i);
        }
        for (int i = 0; i < t.size(); i++){
            buffer ^= t.at(i);
        }
        return (char) buffer;
    }
};