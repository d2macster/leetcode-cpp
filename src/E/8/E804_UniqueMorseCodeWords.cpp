//
// Created by Andrii Cherniak on 5/22/18.
//
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        vector<string> code;
        unordered_set<string> ss;
        for (string c: {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
                        ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
                        ".--", "-..-", "-.--", "--.."})
            code.push_back(c);
        for (string w: words){
            string morse = "";
            for (char c: w) morse += code[c-'a'];
            ss.insert(morse);
        }

        return ss.size();

    }
};