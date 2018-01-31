//
// Created by Andrii Cherniak on 1/12/18.
//

#include <string>

using std::string;

class Solution {
public:
    string toHex(int num) {
        string result = "";
        char h[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        bool first = true;
        for (int i = 28; i >=0; i-=4){
            int n = (num >> i) & 0b1111;
            if ((n != 0) || !first)
            result += h[n];
            if (n != 0) first = false;
        }
        if (first) result += "0";
        return result;
    }
};