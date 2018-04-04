//
// Created by Andrii Cherniak on 4/4/18.
//
#include <unordered_set>
#include <unordered_map>

#include <string>
using namespace std;

class ValidWordAbbr {
    unordered_map<string, int> hash;
    unordered_set<string> dict;

    string abbreviate(string & word){
        int L = word.size();
        if (L <= 2) return word;
        return (word[0] + to_string(L-2) + word[L-1]);
    }
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (string & word: dictionary) {
            if (dict.find(word) == dict.end()) {
                hash[abbreviate(word)]++;
                dict.insert(word);
            }
        }
    }

    bool isUnique(string word) {
        string abbr = abbreviate(word);
        return (hash.find(abbr) == hash.end() || (hash[abbr] == 1 && dict.find(word) != dict.end()));
    }
};