#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int l=0, r=0, odd=0, curr=0, res=0;

    while (r < nums.size()) {
        if (nums[r++] & 1) {
            ++odd;
            curr = 0;
        }

        while (odd == k) {
            odd -= (nums[l++] & 1);
            ++curr;
        }

        res += curr;
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {2, 4, 1, 1, 2, 2, 1, 1};

    cout << numberOfSubarrays(test_case, 2) << endl;

    return 0;
}
