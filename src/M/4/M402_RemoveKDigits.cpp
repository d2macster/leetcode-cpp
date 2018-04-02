//
// Created by Andrii Cherniak on 4/2/18.
//
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k <= 0)
            return num;
        int L = num.size();
        if (L == k) return "0";
        vector<char > digits;
        for (char n: num){
            while (digits.size() > 0 && k > 0 && digits[digits.size() - 1] > n){
                    digits.pop_back();
                    k--;
            }
            digits.push_back(n);
        }
        while (k > 0) {
            digits.pop_back();
            k--;
        }
        L = digits.size();
        int  i = 0;
        for (; i < L && digits[i] == '0';i++){}

        ostringstream oss;
        for (; i < L; i++) oss << digits[i];
        string result = oss.str();
        return (result == "")?"0":result;
    }
};