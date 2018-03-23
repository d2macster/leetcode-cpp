//
// Created by Andrii Cherniak on 3/22/18.
//
#include <vector>

using namespace std;

bool ssort(const string &s1, const string &s2) {
    return (s1.size() != s2.size())?(s1.size() < s2.size()):s1 < s2;
}

class Solution {
    bool check_substring(string &s1, string &s2) {
        int L1 = s1.size();
        int L2 = s2.size();
        int j = 0;
        for (int i = 0; i <L1; i++){
            while (j < L2 && s2[j] != s1[i])j++;
            if (j == L2) return false;
            j++;
        }
        return true;
    }

public:
    int findLUSlength(vector<string> &strs) {
        sort(strs.begin(), strs.end(), ssort);


        int L = strs.size();
        for (int i = L - 1; i >= 0; i--) {
            if (
                    (i == 0 && strs[0] != strs[1]) ||
                            (i == L-1 && strs[i] != strs[i - 1]) ||
                            (strs[i] != strs[i-1] && strs[i] != strs[i+1])){
                
                int j = i + 1;
                bool is_substring = false;
                while (!is_substring && j < L) {
                    bool check = check_substring(strs[i], strs[j]);

                    if (check) is_substring = true;
                    j++;
                }
                if (!is_substring) return strs[i].size();
            }
        }
        return -1;
    }
};