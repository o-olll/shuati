#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "utils.h"

using namespace std;

bool isReflected(vector<pair<int, int>>& points)
{
    int minX, maxX, m;
    unordered_map<int, unordered_set<int>> coordinates;

    minX = INT_MAX;
    maxX = INT_MIN;

    for (const auto& p : points) {
        minX = min(p.first, minX);
        maxX = max(p.first, maxX);
        coordinates[p.first].insert(p.second);
    }

    m = (minX + maxX);

    for (const auto& p : points) {
        if (!coordinates[m-p.first].count(p.second)) {
            return false;
        }
    }

    return true;
}

int main(int argc, char** argv)
{
    vector<pair<int,int>> test_case = {{1,3},{1,4},{1,3}};

    cout << boolalpha << isReflected(test_case) << endl;

    return 0;
}
