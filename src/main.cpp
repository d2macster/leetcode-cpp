//
// Created by Andrii Cherniak on 1/8/18.
//
#import <iostream>
#include <vector>
#include "E/E389_FindDifference.cpp"

using namespace std;

int main() {
    cout << "main running" << endl;
    static const int arr[] = {2, 7, 11, 15};
    vector<int> nums = vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));

    auto s = new Solution();
    cout << s->findTheDifference("abcd", "abcde") << endl;

    delete s;
    return 0;
}

