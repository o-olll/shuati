#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int search(vector<int>& nums, int target)
{
    int l, r, m;

    l = 0;
    r = nums.size()-1;

    while (l <= r) {
        m = l + (r-l)/2;
        // printf("l=%d r=%d m=%d\n", l, r, m);
        if (nums[m] == target)
            return m;
        if ((nums[m]>nums[l] && target>=nums[l] && target<nums[m]) ||
            (nums[m]<nums[r] && !(target>nums[m] && target<=nums[r]))) {
            r = m-1;
        } else {
            l = m+1;
        }
    }

    return -1;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {13,14};
    cout << search(test_case, atoi(argv[1]));

    return 0;
}
