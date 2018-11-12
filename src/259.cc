#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int threeSumSmaller(vector<int>& nums, int target)
{
    int l, r, i, res;

    res = 0;

    sort(nums.begin(), nums.end());

    for (i=0; i<nums.size()-2; ++i) {
        l = i+1;
        r = nums.size()-1;
        while (l < r) {
            if (nums[i] + nums[l] + nums[r] < target) {
                res += r-l;
                ++l;
            } else {
                --r;
            }
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {7, 0, 1, 6,-2,-5, 3,-3, 5,-8,-1,-4,-7, 8,10, 9,-9,-10, 4,-6, 2};

    cout << threeSumSmaller(test_case, atoi(argv[1])) << endl;

    return 0;
}
