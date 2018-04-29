//
// Created by Andrii Cherniak on 4/29/18.
//
#include <string>
#include <sstream>
#include <istream>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' ||
            c == 'U');
}

class Solution {
public:
    string toGoatLatin(string S) {
        if (S == "") return "";
        istringstream in(S);
        ostringstream oss;
        string s;
        string postfix = "a";
        bool first = true;

        while (in >> s){
            if (!isVowel(s[0])){
                s += s[0];
                s = s.substr(1, s.size()-1);
            }
            s += "ma" + postfix;
            if (!first) oss << " ";
            oss << s;
            postfix += 'a';
            first = false;
        }
        return oss.str();
    }
};