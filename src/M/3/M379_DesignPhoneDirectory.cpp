//
// Created by Andrii Cherniak on 3/6/18.
//
#include <set>
using std::set;

class PhoneDirectory {
    int L = 0;
    set<int > assigned_numbers, free_numbers;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        L = maxNumbers;
        for (int i = 0; i < maxNumbers; i++) free_numbers.insert(i);
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (free_numbers.empty()) return -1;
        int n = *free_numbers.begin();
        assigned_numbers.insert(n);
        free_numbers.erase(n);
        return n;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return (free_numbers.find(number) != free_numbers.end());
    }

    /** Recycle or release a number. */
    void release(int number) {
        assigned_numbers.erase(number);
        free_numbers.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */