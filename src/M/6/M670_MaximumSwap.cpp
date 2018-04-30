//
// Created by Andrii Cherniak on 4/29/18.
//
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int L = s.size();
        map<char, set<int> > digits;

        for (int i = 0; i < L; i++)
            digits[s[i]].insert(i);

        int new_num = num;
        bool swapped = false;

        for (int i = 0; i < L - 1; i++) {
            digits[s[i]].erase(i);
            if (digits[s[i]].empty()) digits.erase(s[i]);


            for (auto it = digits.rbegin(); it != digits.rend() && it->first > s[i]; it++) {
                for (int s_id: it->second) {
                    swap(s[i], s[s_id]);
                    new_num = max(new_num, stoi(s));
                    swap(s[i], s[s_id]);
                }
            }

            if (new_num > num) return new_num;
        }
        return num;
    }
};