//
// Created by Andrii Cherniak on 3/22/18.
//
#include <string>
#include <map>
#include <limits>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        map<char , int> m;
        int L = s.size();
        char c;
        map<char , int>::iterator it;
        for (int i = L-1; i >= 0; i--){
            c = s[i];
            m[c] = i;
            it = m.upper_bound(c);

            if (it != m.end() && it->first > c){
                swap(s[i], s[it->second]);
                sort(s.begin()+i+1, s.end());
                long next = stol(s);
                return (next > n && next <= INT_MAX)?next:-1;
            }
        }
        return -1;
    }
};