//
// Created by Andrii Cherniak on 3/12/18.
//

#include <unordered_map>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        queue<UndirectedGraphNode *> toVisit;
        UndirectedGraphNode * copy = new UndirectedGraphNode(node->label);
        mp[node] = copy;

        toVisit.push(node);


        while (!toVisit.empty()) {
            UndirectedGraphNode *n = toVisit.front();
            toVisit.pop();
            for (UndirectedGraphNode * next : n->neighbors){
                if (mp.find(next) == mp.end()){
                    UndirectedGraphNode* next_copy = new UndirectedGraphNode(next->label);
                    toVisit.push(next);
                    mp[next] = next_copy;
                }
                mp[n]->neighbors.push_back(mp[next]);
            }
        }

        return copy;
    }
};