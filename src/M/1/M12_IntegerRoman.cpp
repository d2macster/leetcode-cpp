//
// Created by Andrii Cherniak on 3/16/18.
//
#include <string>
#include <map>

using namespace std;

class Solution {
    map<int, string> roman;

    string converter(int n) {
        if (n <= 0)
            return "";
        map<int, string>::iterator ge = roman.lower_bound(n);

        if (ge == roman.end()) {
            ge--;
            return ge->second + converter(n - ge->first);
        }
        if (n == ge->first) return ge->second;
        else {
            if (ge == roman.begin()) return ge->second + converter(n - ge->first);
            for (auto it = roman.begin(); it != ge; it++) {
                if (ge->first - it->first == n) return it->second + ge->second;
            }
            ge--;
            return ge->second + converter(n - ge->first);
        }
    }

public:
    string intToRoman(int num) {
        roman[1] = "I";
        roman[5] = "V";
        roman[10] = "X";
        roman[50] = "L";
        roman[100] = "C";
        roman[500] = "D";
        roman[1000] = "M";

        if (num < 1)
            return "";

        string ns = to_string(num);
        int power = 1;
        string romanSTR = "";
        for (int i = ns.size() - 1; i >= 0; i--) {
            int v = (ns.at(i) - '0') * power;
            if (v) romanSTR = converter(v) + romanSTR;
            power *= 10;
        }

        return romanSTR;

    }
};