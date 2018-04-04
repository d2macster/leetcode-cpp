//
// Created by Andrii Cherniak on 4/3/18.
//

#include <vector>

using namespace std;

class ZigzagIterator {
    vector<int>::iterator it_v1, it_v2, it_v1_end, it_v2_end;
    vector<int> id_list;
public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) {
        it_v1 = v1.begin();
        it_v2 = v2.begin();
        it_v1_end = v1.end();
        it_v2_end = v2.end();
        if (it_v1 != it_v1_end) id_list.push_back(1);
        if (it_v2 != it_v2_end) id_list.push_back(2);
    }

    int next() {
        int v = 0;
        int next_id = *id_list.begin();
        if (next_id == 1){
            v = *it_v1;
            it_v1++;
            id_list.erase(id_list.begin());
            if (it_v1 != it_v1_end)
                id_list.push_back(next_id);
        }
        if (next_id == 2){
            v = *it_v2;
            it_v2++;
            id_list.erase(id_list.begin());
            if (it_v2 != it_v2_end)
                id_list.push_back(next_id);
        }

        return v;
    }

    bool hasNext() {
        return !id_list.empty();
    }
};
