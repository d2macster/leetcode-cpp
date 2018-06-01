//
// Created by Andrii Cherniak on 5/31/18.
//
#include <string>

using namespace std;

class Solution {
    bool checkDouble(string &s, int l, int r) {
        int dotId = -1;
        for (int i = l; i <= r; i++) {
            if (s[i] == '.')
                if (dotId == -1) dotId = i;
                else return false;
        }
        if (dotId == -1){
            if (!checkInt1(s, l, r)) return false;
            if (s[l] == '-')l++;
            if (l > r) return false;
            return true;
        }
        else{
            if (!(checkInt1(s, l, dotId - 1) && checkInt2(s, dotId + 1, r))) return false;
            if (s[l] == '-')l++;
            if (!((l <= dotId - 1) || (r >= dotId + 1))) return false;
            return true;
        }
    }

    bool checkInt1(string &s, int l, int r) {
        if (l > r) return true;
        if (s[l] == '+' || s[l] == '-') {
            l++;
        }
        for (int i = l; i <= r; i++) {
            if ('0' <= s[i] && s[i] <= '9') {}
            else return false;
        }
        return true;
    }

    bool checkInt2(string &s, int l, int r) {
        if (l > r) return true;
        for (int i = l; i <= r; i++) {
            if ('0' <= s[i] && s[i] <= '9') {}
            else return false;
        }
        return true;
    }

    bool checkIntE(string &s, int l, int r) {
        if (l > r) return false;
        if (s[l] == '+' || s[l] == '-')
            l++;
        if (l > r) return false;
        for (int i = l; i <= r; i++) {
            if ('0' <= s[i] && s[i] <= '9') {}
            else return false;
        }
        return true;
    }

public:
    bool isNumber(string s) {
        int L = s.size();
        if (L == 0) return true;
        int l = 0, r = L - 1;
        for (; l < L && s[l] == ' '; l++) {};
        for (; r >= 0 && s[r] == ' '; r--) {};
        if (l > r || l >= L || r < 0) return false;
        int eId = -1;
        for (int i = l; i <= r; i++) {
            if (s[i] == 'e')
                if (eId == -1) eId = i;
                else return false;
        }
        if (eId == 0) return false;
        if (eId == -1) return checkDouble(s, l, r);
        else
            return checkDouble(s, l, eId - 1) && checkIntE(s, eId + 1, r) && (l <= eId - 1);
    }
};