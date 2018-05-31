//
// Created by Andrii Cherniak on 5/31/18.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int N = rooms.size();
        if (N == 1)return true;
        vector<bool> visited = vector<bool>(N, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int r = q.front();
            visited[r] = true;
            q.pop();
            for (int next: rooms[r])
                if (!visited[next]) q.push(next);
        }
        for (bool v: visited) if (!v) return false;
        return true;
    }
};