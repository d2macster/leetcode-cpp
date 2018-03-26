//
// Created by Andrii Cherniak on 3/26/18.
//
#include <vector>

using namespace std;

class Solution {

    bool dfs(int n, vector<vector<int> > &depends_on, vector<bool> &visited, vector<bool> & path, vector<int> & order) {
        if (visited[n])
            return false;
        path[n] = visited[n] = true;
        for (int next: depends_on[n]){
            if (path[next] || dfs(next, depends_on, visited, path, order)) return true;
        }
        order.push_back(n);
        return path[n] = false;
    }

public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> > &prerequisites) {
        vector<vector<int> > depends_on = vector<vector<int> >(numCourses, vector<int>());
        for (pair<int, int> p: prerequisites) depends_on[p.first].push_back(p.second);

        vector<bool> visited = vector<bool>(numCourses, false);
        vector<bool> path = vector<bool>(numCourses, false);

        vector<int> order;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfs(i, depends_on, visited, path, order)){
                return vector<int>();
            }
        }

        return order;
    }
};