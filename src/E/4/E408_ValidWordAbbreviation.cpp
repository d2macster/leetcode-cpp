//
// Created by Andrii Cherniak on 3/16/18.
//
#include <string>

using namespace std;

class Solution {
    bool check(string &word, string &abbr, int w_id, int a_id, int Lw, int La) {
        if (w_id == Lw && a_id == La) return true;
        else if (w_id >= Lw || a_id >= La) return false;
        if (isalpha(abbr.at(a_id))){
            if (word.at(w_id) != abbr.at(a_id)) return false;
            else return check(word, abbr, w_id+1, a_id+1, Lw, La);
        } else{
            int skip = 0;
            while (a_id < La && isdigit(abbr.at(a_id))){
                if (!skip && abbr.at(a_id) == '0')
                    return false;
                skip = 10 * skip + (abbr.at(a_id) - '0');
                a_id++;
            }
            return check(word, abbr, w_id+skip, a_id, Lw, La);
        }
    }

public:
    bool validWordAbbreviation(string word, string abbr) {
        int Lw = word.size();
        int La = abbr.size();
        if (La > Lw) return false;
        return check(word, abbr, 0, 0, Lw, La);
    }
};