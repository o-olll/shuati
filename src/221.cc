#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int maximalSquare(vector<string>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int m=matrix.size(), n=matrix[0].size(), res=0;
    vector<int> dp(n, 0), current(n);

    for (int i=0,j; i<m; ++i) {
        for (j=0; j<n; ++j) {
            if (matrix[i][j] == '0') {
                current[j] = 0;
            } else {
                current[j] = min(min(j>0?current[j-1]:0, dp[j]), j>0?dp[j-1]:0) + 1;
            }
            res = max(res, current[j]);
            //printf("%d ", current[j]);
        }
        //cout << endl;
        dp.swap(current);
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"10100",
                                "10111",
                                "11111",
                                "10010"};

    vector<string> test_case2 = {"11111111",
                                 "11111110",
                                 "11111110",
                                 "11111000",
                                 "01111000"};

    cout << maximalSquare(test_case2);

    return 0;
}
