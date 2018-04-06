//
// Created by Andrii Cherniak on 4/5/18.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int L1 = s1.size();
        int L2 = s2.size();
        if (L1 == 0 || L2 < L1) return false;
        vector<int> hash1 = vector<int>(26, 0);
        vector<int> hash2 = vector<int>(26, 0);

        for (char c: s1) hash1[c - 'a']++;
        int left = 0;
        for (int right = 0; right < L2; right++) {
            char cR = s2[right];
            hash2[cR - 'a']++;
            while (hash2[cR - 'a'] > hash1[cR - 'a']) {
                char cL = s2[left++];
                hash2[cL - 'a']--;
            }
            if (hash1 == hash2) return true;

        }
        return false;
    }
};