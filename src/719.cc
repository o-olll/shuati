#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int smallestDistancePair(vector<int>& nums, int k)
{
    if (nums.size() < 2)
        return 0;

    int l, r, m, i, j, count;

    sort(nums.begin(), nums.end());

    l = 0;
    r = nums.back() - nums.front();

    while (l < r) {
        m = (l+r) / 2;
        count = 0;
        for (i=0, j=1; i<nums.size(); ++i) {
            while (j<nums.size() && nums[j]-nums[i]<=m) {
                ++j;
            }
            count += j-i-1;
        }

        printf("l=%d r=%d m=%d count=%d\n", l, r, m, count);
        if (count < k)
            l = m+1;
        else
            r = m;
    }

    return l;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {9,7,4,3,1};

    cout << smallestDistancePair(test_case, atoi(argv[1])) << endl;

    return 0;
}
