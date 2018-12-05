#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    unordered_map<int,int> counts;
    vector<int> sums;
    int res = 0;

    counts[0] = 1;

    for (int i=0, sum=0; i<nums.size(); ++i) {
        sum += nums[i];
        res += counts[sum-k];
        ++counts[sum];
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {-1,2,-1,3,4,-1,-3};

    cout << subarraySum(test_case, 3) << endl;

    return 0;
}
