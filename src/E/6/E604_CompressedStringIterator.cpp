//
// Created by Andrii Cherniak on 3/23/18.
//
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

class StringIterator {
    vector<char > char_v;
    vector<int > len_v;
    int L = 0;
public:
    StringIterator(string compressedString) {
        istringstream in(compressedString);
        char c;
        int l;
        while (in >> c){
            char_v.push_back(c);
            in >> l;
            len_v.push_back(l);
        }
    }

    char next() {
        if (hasNext()) {
            char c = char_v[L];
            len_v[L]--;
            if (len_v[L] == 0) L++;
            return c;
        } else return ' ';
    }

    bool hasNext() {
        return (L < char_v.size() && len_v[L]);
    }
};