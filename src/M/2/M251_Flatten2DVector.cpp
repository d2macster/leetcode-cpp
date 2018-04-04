//
// Created by Andrii Cherniak on 4/3/18.
//
#include <vector>

using namespace std;

class Vector2D {
    vector<vector<int> >::iterator it2, it_end2;
    vector<int >::iterator it1, it_end1;
public:
    Vector2D(vector<vector<int> > &vec2d) {
        it2 = vec2d.begin();
        it_end2 = vec2d.end();
        if (it2 != it_end2) {
            it1 = it2->begin();
            it_end1 = it2->end();
        }
        if (it1 == it_end1) iterate();
    }
    void iterate(){
        if (it1 != it_end1) it1++;
        while (it1 == it_end1 && it2 != it_end2){
            it2++;
            if (it2 != it_end2){
                it1 = it2->begin();
                it_end1 = it2->end();
            }
        }
    }

    int next() {
        int v = *it1;
        iterate();
        return v;
    }

    bool hasNext() {
        return (it2 != it_end2 && it1 != it_end1);
    }
};
