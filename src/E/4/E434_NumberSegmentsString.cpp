//
// Created by Andrii Cherniak on 3/16/18.
//
#include <string>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int segments = 0;
        bool isSegment = false;
        for (char ch: s) {
            if (!isspace(ch)) {
                if (!isSegment)
                    segments++;
                isSegment = true;
            } else isSegment = false;
        }
        return segments;
    }
};