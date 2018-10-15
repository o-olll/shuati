#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days)
{
    if (days.empty() || days[0].empty())
        return 0;

    vector<int> dp(days.size(), INT_MIN), temp(days.size());
    int c, w, k, C, W, res;

    C = days.size();
    W = days[0].size();
    dp[0] = 0;

    for (c=0; c<C; ++c)
        flights[c][c] = 1;

    for (w=0; w<W; ++w) {
        for (c=0; c<C; ++c) {
            temp[c] = INT_MIN;
            for (k=0; k<C; ++k) {
                if (flights[k][c] == 1)
                    temp[c] = max(temp[c], dp[k] + days[c][w]);
            }
        }
        dp = temp;
    }

    return max(0, *max_element(dp.begin(), dp.end()));
}

int main(int argc, char** argv)
{
    vector<vector<int>> flights = {{0,1,0},
                                   {1,0,1},
                                   {0,1,0}},

                        days = {{1,2,1,2},
                                {6,0,2,5},
                                {4,3,1,3}};

    cout << maxVacationDays(flights, days) << endl;

    return 0;
}
