//
// Created by Andrii Cherniak on 3/20/18.
//
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
    void helper(vector<int> &product, int shift, string &num1, int d) {
        int L = num1.size();
        int overflow = 0;
        int p = 0, i = L - 1;
        for (i = L - 1; i >= 0 || overflow > 0; i--, shift--) {
            overflow += product[shift];
            p = (i >= 0) ? (num1[i] - '0') : 0;
            p = p * d + overflow;
            product[shift] = p % 10;
            overflow = p / 10;
        }
    }

public:
    string multiply(string num1, string num2) {
        int L1 = num1.size();
        int L2 = num2.size();
        if (L1 == 0 || L2 == 0)
            return "0";
        vector<int> product = vector<int>(L1 + L2, 0);
        for (int i = L2 - 1; i >= 0; i--) {
            helper(product, L1 + i, num1, num2[i] - '0');
        }
        ostringstream oss;
        int i = 0;
        while (i < L1 + L2 && product[i] == 0) i++;
        if (i == L1 + L2) oss << 0;
        while (i < L1 + L2) oss << product[i++];
        return oss.str();
    }
};