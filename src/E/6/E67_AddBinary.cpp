//
// Created by Andrii Cherniak on 3/12/18.
//
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int La = a.size();
        int Lb = b.size();
        int overflow = 0;
        string result = "";

        for (int pa = La - 1, pb = Lb - 1; pa >= 0 || pb >= 0 || overflow; pa--, pb--) {
            int va = (pa >= 0) ? a[pa] - '0' : 0;
            int vb = (pb >= 0) ? b[pb] - '0' : 0;
            int v = va + vb + overflow;
            overflow = ((v & 2) >> 1);
            v &= 1;
            result = (char) (v + '0') + result;
        }

        return result;
    }
};