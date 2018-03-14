//
// Created by Andrii Cherniak on 3/14/18.
//
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if (n < 1 || k < 1)
            return "";
        string result = "";
        set<int> s;
        vector<int> factorial = vector<int>(n + 1, 1);
        for (int i = 1; i <= n; i++) s.insert(i);
        for (int i = 1; i <= n; i++) factorial[i] = factorial[i - 1] * i;
        while (n > 0) {
            int s_id = (k - 1) / factorial[n - 1];
            set<int>::iterator it = s.begin();
            advance(it, s_id);
            int v = *it;
            result = result + to_string(v);
            s.erase(v);
            k -= s_id * factorial[n - 1];
            n--;
        }
        return result;
    }
};