//
// Created by Andrii Cherniak on 5/10/18.
//
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>

using namespace std;

class Solution {
    bool dfs(char c, map<char, set<char>> &graph, map<char, int> &alphabet, string &result) {
        if (alphabet[c] == 1) return true;
        if (alphabet[c] == -1) return false;
        alphabet[c] = -1;
        for (char next_c: graph[c]) {
            if (!dfs(next_c, graph, alphabet, result)) return false;
        }
        alphabet[c] = 1;
        result += c;
        return true;
    }

public:
    string alienOrder(vector<string> &words) {
        int L = words.size();

        map<char, int> alphabet;
        map<char, set<char>> graph;
        for (auto &w: words)
            for (char ch: w) alphabet[ch] = 0;

        if (alphabet.empty()) return "";

        for (int i = 0; i < L - 1; i++) {
            for (int j = 0; j < min(words[i].size(), words[i + 1].size()); j++)
                if (words[i][j] != words[i + 1][j]) {
                    graph[words[i][j]].insert(words[i + 1][j]);
                    break;
                }
        }

        string result = "";

        for (auto it: alphabet) {
            if (alphabet[it.first] == 0) {
                if (!dfs(it.first, graph, alphabet, result)) return "";
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};