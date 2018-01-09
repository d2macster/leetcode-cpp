//
// Created by Andrii Cherniak on 1/8/18.
//
#import <iostream>
#include <vector>
#include "E/E1_TwoSum.cpp"
using namespace std;
int main(){
    cout << "main running" << endl;
    static const int arr[] = {2, 7, 11, 15};
    vector<int> nums = vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]) );

    E1_TwoSum* s = new E1_TwoSum();
    vector<int> result = s->twoSum(nums, 9);
    for (int id: result){
        cout << id <<  endl;
    }

    delete s;
    return 0;
}

