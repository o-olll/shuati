#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int mergeSort(vector<long>& nums, int l, int r, vector<long>& sorted)
{
    if (r-l <= 1)
        return 0;

    int count, m, i, j, k;

    m = (l+r) / 2;

    count = mergeSort(nums, l, m, sorted) +
        mergeSort(nums, m, r, sorted);

    for (i=l, j=m; i<m; ++i) {
        while (j<r && nums[i]>(nums[j]+nums[j]))
            ++j;
        count += j-m;
    }

    for (k=l,i=l,j=m; k<r; ++k) {
        if (j==r || (i<m && nums[i]<nums[j]))
            sorted[k] = nums[i++];
        else
            sorted[k] = nums[j++];
    }

    for (k=l; k<r; ++k) {
        nums[k] = sorted[k];
    }

    return count;
}

int reversePairs(vector<int>& nums)
{
    vector<long> longNums(nums.begin(), nums.end()), sorted(nums.size());

    return mergeSort(longNums, 0, nums.size(), sorted);
}

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    cout << reversePairs(test_case) << endl;

    return 0;
}
