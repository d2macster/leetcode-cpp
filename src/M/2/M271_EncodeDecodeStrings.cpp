//
// Created by Andrii Cherniak on 3/22/18.
//
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        ostringstream out;
        out << strs.size();
        for (string &s: strs) out << ':' << s.size();
        for (string &s: strs) out << ':' << s;
        return out.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        vector<int> sl;
        int L = s.size();
        int i = 0;
        int N = 0;
        while (i < L && s[i] != ':') {
            N = N * 10 + (s[i] - '0');
            i++;
        }
        i++;
        for (int j = 1; j <= N; j++) {
            int l = 0;
            while (i < L && s[i] != ':') {
                l = l * 10 + (s[i] - '0');
                i++;
            }
            sl.push_back(l);
            i++;
        }
        for (int j = 1; j <= N; j++) {
            string ss = "";
            for (int k = 1; k <= sl[j-1]; k++) ss += s[i++];
            result.push_back(ss);
            i++;
        }
        return result;
    }
};