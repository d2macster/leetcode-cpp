//
// Created by Andrii Cherniak on 2/12/18.
//

#include <vector>

using std::vector;


class Solution {
    void dfs(vector<vector<int> > &M, vector<int> & friends, int friend_id, int F) {
        if (friends[friend_id] == 0){
            friends[friend_id] = 1;
            for (int i = 0; i < F; i++)
                if (M[friend_id][i] == 1 && friends[i] == 0) dfs(M, friends, i, F);
        }
    }

public:
    int findCircleNum(vector<vector<int> > &M) {
        int F = M.size();
        if (F == 0) return 0;
        int counter = 0;
        vector<int> friends = vector<int>(F, 0);
        for (int i = 0; i < F; i++)
            if (friends[i] == 0) {
                counter++;
                dfs(M, friends, i, F);
            }
        return counter;
    }
};