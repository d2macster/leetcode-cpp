//
// Created by Andrii Cherniak on 4/10/18.
//
#include <string>
#include <>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int L1 = num1.size();
        int L2 = num2.size();

        if (L1 < L2) return addStrings(num2, num1);
        int carry = 0;
        int i1 = L1 - 1, i2 = L2 - 1;
        for(; i2 >= 0 || (carry > 0 && i1 >= 0);i1--, i2--){
            int v = (i2 >= 0)? (num2[i2] - '0'): 0;
            v += (num1[i1] - '0') + carry;
            carry = v / 10;
            v %= 10;
            num1[i1] = ('0' + v);
        }

        return (carry == 0)?num1:"1"+num1;
    }
};