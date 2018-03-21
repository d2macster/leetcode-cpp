//
// Created by Andrii Cherniak on 3/21/18.
//
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
    vector<int> parse(string &a) {
        istringstream iss(a);
        vector<int> number = vector<int>(2, 0);
        iss >> number[0];
        char plus;
        iss >> plus;
        iss >> number[1];
        return number;
    }

public:
    string complexNumberMultiply(string a, string b) {
        vector<int> va = parse(a);
        vector<int> vb = parse(b);
        vector<int> p = vector<int>(2, 0);
        p[0] = va[0] * vb[0] - va[1] * vb[1];
        p[1] = va[0] * vb[1] + va[1] * vb[0];
        ostringstream oss;
        oss << p[0] << "+" << p[1] << "i";
        return oss.str();
    }
};