//
// Created by Andrii Cherniak on 4/10/18.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
    string minDiff(string &CC) {
        if (CC[0] == CC[1]) return CC;
        int ii = stoi(CC, 0, 16);
        int minD = 99999999;
        string minII = "";
        for (string vv: {"00", "11", "22", "33", "44", "55", "66", "77", "88", "99", "aa", "bb", "cc", "dd", "ee",
                         "ff"}) {
            int d = abs(ii - stoi(vv, 0, 16));

            if (d < minD) {
                minD = d;
                minII = vv;
            }
        }
        return minII;
    }

public:
    string similarRGB(string color) {
        string RR = color.substr(1, 2);
        string GG = color.substr(3, 2);
        string BB = color.substr(5, 2);


        string newRR = minDiff(RR);
        string newGG = minDiff(GG);
        string newBB = minDiff(BB);
        return "#" + newRR + newGG + newBB;

    }
};