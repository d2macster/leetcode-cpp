//
// Created by Andrii Cherniak on 3/8/18.
//
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

struct char_count {
    char ch;
    int counter;
};

bool operator<(const char_count &cc1, const char_count &cc2) {
    return cc1.counter > cc2.counter;
}

class Solution {
public:
    string reorganizeString(string S) {
        int L = S.size();
        if (L <= 1) return S;
        vector<int> counter = vector<int>(26, 0);
        vector<char_count> vcc;

        for (char ch: S) counter[ch - 'a']++;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (counter[ch - 'a']) {
                if (counter[ch - 'a'] > (L+1)/2)
                    return "";
                char_count cc = {ch, counter[ch - 'a']};
                vcc.push_back(cc);
            }
        }
        std::sort(vcc.begin(), vcc.end());
        int S_id = 0;
        for (char_count cc:vcc){
            for (int i = 1; i <= cc.counter; i++){
                S[S_id] = cc.ch;
                S_id ++;
            }
        }
        string result = "";
        for (int i = 0, j = (L+1)/2; i < (L+1)/2, j < L; i++,j++){
            result = result + S[i] + S[j];
        }
        if (L&1)
        result = result + S[(L+1)/2 - 1];


        return result;
    }
};