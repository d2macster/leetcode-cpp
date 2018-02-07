//
// Created by Andrii Cherniak on 2/6/18.
//
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
    unordered_map<string, string> forward, backwards;
    long counter = 0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (forward.find(longUrl) != forward.end()) return forward[longUrl];
        else{
            string tinyUrl = "http://tinyurl.com/" + counter;
            counter++;
            forward[longUrl] = tinyUrl;
            backwards[tinyUrl] = longUrl;
            return tinyUrl;
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return backwards[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));