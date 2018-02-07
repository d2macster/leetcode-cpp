//
// Created by Andrii Cherniak on 2/6/18.
//
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using std::string;
using std::unordered_map;
using std::rand;


class Solution {
    unordered_map<string, string> forward, backwards;
    const string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

public:

    Solution() {
        srand(time(NULL));
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while (forward.find(longUrl) == forward.end()) {
            string hash;
            int id;
            for (int i = 0; i < 10; i++) {
                id = rand() % alphanum.size();
                hash += alphanum[id];
            }

            string tinyUrl = "http://tinyurl.com/" + string(hash);
            if (backwards.find(tinyUrl) == backwards.end()) {
                forward[longUrl] = tinyUrl;
                backwards[tinyUrl] = longUrl;
            }
        }
        return forward[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return backwards[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));