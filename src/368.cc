#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums)
{
    if (nums.size() < 2)
        return nums;

    vector<int> dp(nums.size(), 0), parent(nums.size(), 0), res;
    int maxLen = 0, maxId = 0, i, j;

    for (i=nums.size()-1; i>=0; --i) {
        for (j=i; j<nums.size(); ++j) {
            if (nums[j]%nums[i]==0 && dp[i]<dp[j]+1) {
                dp[i] = dp[j]+1;
                parent[i] = j;
                if (maxLen < dp[i]) {
                    maxLen = dp[i];
                    maxId = i;
                }
            }
        }
    }

    while (maxId != parent[maxId]) {
        res.push_back(nums[maxId]);
        maxId = parent[maxId];
    }
    res.push_back(nums[maxId]);
    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {4,5,8,10,20}, res;

    res = largestDivisibleSubset(test_case);

    utils::printContainer(res.begin(), res.end());

    return 0;
}
