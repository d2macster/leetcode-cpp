//
// Created by Andrii Cherniak on 2/12/18.
//
#include <vector>

using std::vector;

class Solution {
    void helper(vector<vector<int> > &image, int oldColor, int newColor, int r, int c, int R, int C) {
        if (image[r][c] == oldColor) {
            image[r][c] = newColor;
            if (r - 1 >= 0 && image[r - 1][c] == oldColor) helper(image, oldColor, newColor, r - 1, c, R, C);
            if (c + 1 < C && image[r][c + 1] == oldColor) helper(image, oldColor, newColor, r, c + 1, R, C);
            if (r + 1 < R && image[r + 1][c] == oldColor) helper(image, oldColor, newColor, r + 1, c, R, C);
            if (c - 1 >= 0 && image[r][c - 1] == oldColor) helper(image, oldColor, newColor, r, c - 1, R, C);
        }
    }

public:
    vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        int R = image.size();
        int C = image[0].size();

        if (oldColor == newColor)
            return image;

        helper(image, oldColor, newColor, sr, sc, R, C);

        return image;
    }
};