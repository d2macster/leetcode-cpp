//
// Created by Andrii Cherniak on 1/10/18.
//

#include <string>
using std::string;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unsigned int buffer = 0;
        for (char ch : s){
            buffer ^= (int)ch;
        }
        for (char ch : t){
            buffer ^= (int) ch;
        }
        return (char) buffer;
    }
};