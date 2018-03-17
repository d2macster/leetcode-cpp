//
// Created by Andrii Cherniak on 3/16/18.
//
#include <string>
#include <map>

using namespace std;

class Solution {

public:
    string intToRoman(int num) {
        vector<string> i_map = vector<string>();
        for (string s: (string[]) {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"})
            i_map.push_back(s);

        vector<string> x_map = vector<string>();
        for (string s: (string[]) {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"})
            x_map.push_back(s);

        vector<string> c_map = vector<string>();
        for (string s: (string[]) {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"})
            c_map.push_back(s);

        vector<string> m_map = vector<string>();
        for (string s: (string[]) {"", "M", "MM", "MMM", "MMMM"})
            m_map.push_back(s);


        if (num < 1 || num > 4999) return "";
        return m_map[num / 1000] + c_map[(num % 1000) / 100] + x_map[(num % 100) / 10] + i_map[num % 10];

    }
};