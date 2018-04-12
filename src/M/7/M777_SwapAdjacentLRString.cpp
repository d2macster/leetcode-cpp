//
// Created by Andrii Cherniak on 4/11/18.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size()) return false;
        int L = start.size();
        vector<int> startR, startL, endR, endL;
        vector<char > startRL, endRL;

        for (int i = 0; i < L; i++) {
            if (start[i] == 'R') startR.push_back(i);
            if (start[i] == 'L') startL.push_back(i);
            if (start[i] == 'R' || start[i] == 'L') startRL.push_back(start[i]);
        }

        for (int i = 0; i < L; i++) {
            if (end[i] == 'R') endR.push_back(i);
            if (end[i] == 'L') endL.push_back(i);
            if (end[i] == 'R' || end[i] == 'L') endRL.push_back(end[i]);

        }

        if (startR.size() != endR.size() || startL.size() != endL.size()) return false;

        for (int i = 0; i < startR.size(); i++)
            if (startR[i] > endR[i]) return false;
        for (int i = 0; i < startL.size(); i++)
            if (startL[i] < endL[i]) return false;

        return (startRL == endRL);
    }
};