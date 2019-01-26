#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int minCost(vector<vector<int>>& costs) {
    if (costs.empty() || costs[0].empty())
        return 0;

    int n = costs.size();
    vector<int> dp(3, 0), current(3, 0);

    for (const auto& cost : costs) {
        current[0] = min(dp[1],dp[2]) + cost[0];
        current[1] = min(dp[0],dp[2]) + cost[1];
        current[2] = min(dp[0],dp[1]) + cost[2];
        dp.swap(current);
    }

    return min(dp[0], min(dp[1], dp[2]));
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{8,3,6},
                                     {7,4,4},
                                     {5,4,9},
                                     {2,1,3}};
    cout << minCost(test_case);
    return 0;
}
