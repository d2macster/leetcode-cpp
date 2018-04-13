//
// Created by Andrii Cherniak on 4/13/18.
//
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int L = s.size();
        vector<bool > bold = vector<bool>(L, false);
        for (string w: dict){
            int pos = 0;
            size_t found;
            int Lw = w.size();
            while((found = s.find(w, pos)) != string::npos){
                for(int i = found; i < found + Lw; i++) bold[i] = true;
                pos = found + 1;
            }
        }
        ostringstream oss;
        for(int i = 0; i < L; i++){
            if (bold[i] && (i == 0 || !bold[i-1])) oss << "<b>";
            oss << s[i];
            if (bold[i] && (i == L-1 || !bold[i+1])) oss<< "</b>";
        }

        return oss.str();
    }
};