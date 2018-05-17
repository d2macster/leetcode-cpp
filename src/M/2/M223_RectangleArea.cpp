//
// Created by Andrii Cherniak on 5/17/18.
//

class Solution {
    long area(long x1, long y1, long x2, long y2) {
        long dx = x2 - x1;
        long dy = y2 - y1;
        if (dx < 0L || dy < 0L) return 0L;
        return dx * dy;
    }

public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long S1 = area(A, B, C, D);
        long S2 = area(E, F, G, H);
        long xl = max(A, E);
        long yl = max(B, F);
        long xr = min(C, G);
        long yr = min(D, H);
        long S3 = area(xl, yl, xr, yr);
        long result = S1 + S2 - S3;
        return result;
    }
};