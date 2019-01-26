#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int minCostII(vector<vector<int>>& costs)
{
    if (costs.empty() || costs[0].empty()) return 0;

    vector<int> dp(costs[0].size(), 0), current(costs[0].size(), 0), lastMin(2,-1), currMin(2,-1);

    for (const auto& cost : costs) {
        for (int i=0; i<cost.size(); ++i) {
            current[i] = (lastMin[0]==-1 ? 0 : (i==lastMin[0] ? dp[lastMin[1]] : dp[lastMin[0]])) + cost[i];
            if (currMin[0]==-1 || current[i]<current[currMin[0]]) {
                currMin[1] = currMin[0];
                currMin[0] = i;
            } else if (currMin[1]==-1 || current[i]<current[currMin[1]]) {
                currMin[1] = i;
            }
        }
        dp.swap(current);
        lastMin.swap(currMin);
        currMin[0] = currMin[1] = -1;
    }

    return *min_element(dp.begin(), dp.end());
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{8,3,6},
                                     {7,4,4},
                                     {5,4,9},
                                     {2,1,3},
                                     {4,7,5}};
    cout << minCostII(test_case);

    return 0;
}
