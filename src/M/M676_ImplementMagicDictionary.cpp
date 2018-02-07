//
// Created by Andrii Cherniak on 2/7/18.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>


using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;


class MagicDictionary {
    unordered_map<string, int> hash_counter;
    unordered_set<string> words;

public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        char ch;

        for (string w: dict) {
            words.insert(w);
            for (int i = 0; i < w.size(); i++) {
                ch = w[i];
                w[i] = '*';
                hash_counter[w]++;
                w[i] = ch;
            }
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        char ch;

        bool not_seen = (words.find(word) == words.end());
        int counter = 0;

        for (int i = 0; i < word.size(); i++) {
            ch = word[i];
            word[i] = '*';
            counter = std::max(counter, hash_counter[word]);
            word[i] = ch;
        }

        return ((counter > 1) || (counter == 1 && not_seen));
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */