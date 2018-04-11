//
// Created by Andrii Cherniak on 4/11/18.
//
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;

class Solution {
public:
    int wordsTyping(vector<string> &sentence, int rows, int cols) {
        if (rows == 0 || cols == 0) return 0;
        int L = sentence.size();

        int word_id = 0;
        unordered_map<int, int> row_word_fit;

        for (int r = 1; r <= rows; r++) {
            int start = word_id % L;
            if (row_word_fit.find(start) != row_word_fit.end())
                word_id += row_word_fit[start];
            else {
                int pos = 0;
                int word_id_start = word_id;
                while (pos + sentence[word_id % L].size() <= cols) {
                    pos += sentence[word_id % L].size() + 1;
                    word_id++;
                }
                row_word_fit[start] = word_id - word_id_start;
            }
        }

        return word_id / L;
    }
};