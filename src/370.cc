#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<int> getModifiedArray(int length, vector<vector<int>>& updates)
{
    vector<int> res(length+1, 0);

    for (const auto& v : updates) {
        res[v[0]] += v[2];
        res[v[1]+1] -= v[2];
    }

    for (int i=1; i<res.size(); ++i) {
        res[i] += res[i-1];
    }

    res.pop_back();

    return res;
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{1,  4,  2},
                                     {2,  4,  3},
                                     {0,  2, -2}};

    vector<int> res = getModifiedArray(10, test_case);

    utils::printContainer(res.begin(), res.end());

    return 0;
}
