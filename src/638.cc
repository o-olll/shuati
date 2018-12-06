#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int shopping(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int current)
{
    int res = INT_MAX;
    for (int i=0, j; i<special.size(); ++i) {
        vector<int> newNeeds = needs;
        for (j=0; j<needs.size(); ++j) {
            if (special[i][j] > needs[j])
                break;
            newNeeds[j] -= special[i][j];
        }
        if (j == needs.size())
            res = min(res, shopping(price, special, newNeeds, current+special[i].back()));
    }

    for (int i=0; i<needs.size(); ++i) {
            current += needs[i] * price[i];
        }

    return min(current, res);
}

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
{
    return shopping(price, special, needs, 0);
}

int main(int argc, char** argv)
{
    vector<int> price = {2,5}, needs = {4,5};
    vector<vector<int>> special = {{3,0,5}, {1,2,10}, {2,0,4}};

    cout << shoppingOffers(price, special, needs) << endl;

    return 0;
}
