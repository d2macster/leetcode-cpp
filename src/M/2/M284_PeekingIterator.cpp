//
// Created by Andrii Cherniak on 4/3/18.
//
#include <vector>
using namespace std;
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
    vector<int>::const_iterator it, it_end;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        it = nums.begin();
        it_end = nums.end();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return *it;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int v = *it;
        it++;
        return v;
    }

    bool hasNext() const {
        return (it != it_end);
    }
};