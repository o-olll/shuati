#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
{
    int start, i;
    vector<string> res;

    start = lower;

    for (i=0; i<nums.size() && nums[i]<lower; ++i);

    for (; i<nums.size() && nums[i]<=upper; ++i) {
        if (nums[i] <= start) {
            start = nums[i] + 1;
        } else {
            res.push_back(to_string(start) + "->" + to_string(nums[i]-1));
            start = nums[i] + 1;
        }
    }

    if (start <= upper) {
        res.push_back(to_string(start) + "->" + to_string(upper));
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {3,6,9};

    auto res = findMissingRanges(test_case, 5, 9);

    utils::printContainer(res.begin(), res.end());
    return 0;
}
