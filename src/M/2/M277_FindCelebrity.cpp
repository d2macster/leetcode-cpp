//
// Created by Andrii Cherniak on 4/29/18.
//

#include <iostream>
using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        for (int person = 0; person < n; person++) {
            int knows_me = 0, i_know = 0;

            for (int p = 0; p < n; p++)
                if (p != person) {
                    if (knows(person, p)) {
                        i_know++;
                        break;
                    }
                    if (knows(p, person)) knows_me++; else break;
                }

            if ((knows_me == n - 1) && (i_know == 0)) return person;

        }
        return -1;
    }
};