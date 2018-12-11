#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int findUnsortedSubarray(vector<int>& nums)
{
    if (nums.size() < 2)
        return nums.size();
    int mx, mn, start, end, n;
    mx = nums.front();
    mn = nums.back();
    n = nums.size();
    end = -2;
    start = -1;
    for (int i=0; i<nums.size(); ++i) {
        mx = max(mx, nums[i]);
        if (nums[i] < mx)
            end = i;
        mn = min(mn, nums[n-1-i]);
        if (nums[n-1-i] > mn)
            start = n-1-i;
    }
    return end-start+1;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {2,6,4,8,10,9,15};
    cout << findUnsortedSubarray(test_case) << endl;

    return 0;
}
