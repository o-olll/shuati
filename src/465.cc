#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int transfer(vector<int>& balances, int start)
{
    if (start >= balances.size())
        return 0;

    int res = INT_MAX;

    while (start<balances.size() && balances[start] == 0)
        ++start;

    for (int i=start+1; i<balances.size(); ++i) {
        if ((balances[start]>0 && balances[i]<0) || (balances[start]<0 && balances[i]>0)) {
            balances[i] += balances[start];
            res = min(transfer(balances, start+1), res);
            balances[i] -= balances[start];
        }
    }

    return res == INT_MAX ? 0 : res+1;
}

int minTransfers(vector<vector<int>>& transactions)
{
    unordered_map<int, int> accounts;
    vector<int> balances;

    for (auto& tx : transactions) {
        accounts[tx[0]] -= tx[2];
        accounts[tx[1]] += tx[2];
    }

    for (auto it=accounts.begin(); it!=accounts.end(); ++it) {
        cout << it->first << " " << it->second << endl;
        if (it->second != 0)
            balances.push_back(it->second);
    }

    return transfer(balances, 0);
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{1,0,1},{0,2,4},{0,3,6},{2,3,3},{1,2,2}};

    cout << minTransfers(test_case) << endl;

    return 0;
}
