//
// Created by Andrii Cherniak on 3/22/18.
//
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        ostringstream out;
        out << setw(5) << strs.size();
        for (string &s: strs) out << setw(5) << s.size();
        for (string &s: strs) out << s;
        return out.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        vector<int> sl;
        int L = s.size();
        int N = stoi(s.substr(0, 5));
        for (int i = 1; i <= N; i++){
            int l = stoi(s.substr(5*i, 5));
            sl.push_back(l);
        }
        int shift = 5*(N+1);
        for (int i = 0; i < N; i++){
            result.push_back(s.substr(shift, sl[i]));
            shift += sl[i];
        }
        return result;
    }
};