//
// Created by Andrii Cherniak on 2/7/18.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using std::vector;
using std::string;
using std::unordered_map;

class WordDistance {
    unordered_map<string, vector<int> > wp;
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); i++)
            wp[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        int p1 = 0, p2 = 0, d = INT_MAX;
        while (p1 < wp[word1].size() && p2 < wp[word2].size()){
            d = std::min(d, abs(wp[word1][p1] - wp[word2][p2]));
            wp[word1][p1] < wp[word2][p2] ? p1++:p2++;
        }
        return d;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */