#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int findTargetSumWays(vector<int>& nums, int S)
{
    unordered_map<int,int> dp;
    dp[0] = 1;

    for (int num : nums) {
        unordered_map<int,int> t;
        for (const auto& p : dp) {
            t[p.first+num] += p.second;
            t[p.first-num] -= p.second;
        }
        dp.swap(t);
    }

    return dp[S];
}

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    return 0;
}
