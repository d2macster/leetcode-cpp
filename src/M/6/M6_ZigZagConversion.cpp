//
// Created by Andrii Cherniak on 3/14/18.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
    int row_id = 0;
    int rows = 1;
    int increment = 1;

    int getRowId() {
        row_id += increment;
        if (row_id >= rows && increment == 1) increment = -1;
        if (row_id == 1 && increment == -1) increment = 1;
        return row_id;
    }

public:
    string convert(string s, int numRows) {
        rows = numRows;
        if (numRows <= 1) return s;
        int L = s.length();
        if (numRows <= 1 || L <= numRows) return s;
        vector<vector<char> > rows = vector<vector<char> >(numRows, vector<char>());
        for (int i = 0; i < L; i++){
            int row_id = getRowId();
            rows[row_id-1].push_back(s[i]);
        }


        string result = "";
        for (int row = 1; row <= numRows; row++) {
            for (char ch: rows[row - 1]) result = result + ch;
        }

        return result;
    }
};