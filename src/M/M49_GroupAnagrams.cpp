//
// Created by Andrii Cherniak on 2/7/18.
//
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                73, 79, 83, 89, 97, 101};

        vector<vector<string> > result;
        unordered_map<long, vector<string> > cache;
        for(const string w : strs){
            long hash = 1L;
            for (char ch: w) hash *= primes[ch-'a'];
            cache[hash].push_back(w);
        }
        for(auto p: cache)
            result.push_back(p.second);

        return result;
    }
};