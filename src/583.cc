#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1,0));
    for (int i=1,j; i<=word1.size(); ++i) {
        for (j=1; j<=word2.size(); ++j) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return word1.size() + word2.size() - dp.back().back()*2;
}

int main(int argc, char** argv)
{
    cout << minDistance(argv[1], argv[2]);
    return 0;
}
