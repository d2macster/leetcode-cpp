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
        if (!La) return b;
        if (!Lb) return a;
        if (Lb > La) {
            std::swap(La, Lb);
            std::swap(a, b);
        }
        int overflow = 0;

        int pa = La - 1, pb = Lb - 1;
        while (pa >= 0 || pb >= 0) {
            int va = (pa >= 0) ? a[pa] - '0' : 0;
            int vb = (pb >= 0) ? b[pb] - '0' : 0;
            int v = va + vb + overflow;
            cout << v << endl;
            overflow = ((v & 2) >> 1);
            v &= 1;
            a[pa] = (v) ? '1' : '0';
            pa--;
            pb--;
        }
        if (overflow > 0)
            a = '1' + a;
        return a;
    }
};