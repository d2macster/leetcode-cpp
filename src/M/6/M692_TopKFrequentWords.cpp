//
// Created by Andrii Cherniak on 3/19/18.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

struct wordCnt {
    string word;
    int cnt;
};

bool operator<(const wordCnt &wc1, const wordCnt &wc2) {
    return wc1.cnt < wc2.cnt;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> counter;
        for (string w: words) counter[w]++;
        map<int, vector<string> > s_counter;
        for (auto it: counter) s_counter[it.second].push_back(it.first);

        vector<string> topK;
        int cnt = 0;
        for(map<int, vector<string> >::reverse_iterator it = s_counter.rbegin(); it != s_counter.rend(); it++){
            sort(it->second.begin(), it->second.end());
            for (string w: it->second) {
                topK.push_back(w);
                cnt ++;
                if (cnt == k) return topK;
            }
        }

        return topK;

    }
};