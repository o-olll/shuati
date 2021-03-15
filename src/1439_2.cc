#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include "utils.h"

using namespace std;
using VecIt = vector<int>::const_iterator;
using ItPair = pair<VecIt, VecIt>;

int getPairItSum(const ItPair& itPair) {
    return *(itPair.first) + *(itPair.second);
}

vector<int> getSortedSums(const vector<int>& v1, const vector<int>& v2, int k) {
    auto compare = [](pair<VecIt, VecIt> p1, pair<VecIt, VecIt> p2) { return getPairItSum(p1) > getPairItSum(p2); };
    priority_queue<ItPair, vector<ItPair>, decltype(compare)> pq(compare);
    vector<int> out;

    for (auto it=v1.begin(); it!=v1.end(); ++it)
        pq.emplace(it, v2.begin());

    for (int i=0; i<k && !pq.empty(); ++i) {
        auto minItPair = pq.top();
        pq.pop();
        out.push_back(getPairItSum(minItPair));
        cout << "out[" << i << "]: " << out[i] << endl;
        (minItPair.second)++;
        if (minItPair.second != v2.end())
            pq.push(minItPair);
    }

    return out;
}

int kthSmallest(vector<vector<int>>& mat, int k) {
    if (mat.empty() || mat[0].empty() || k==0)
        return INT_MIN;

    vector<int> sortedSums{0};
    
    for (const auto& row: mat) {
        vector<int> newSortedSums = getSortedSums(sortedSums, row, k);
        sortedSums.swap(newSortedSums);
    }

    return *(sortedSums.rbegin());
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{1,10,10}, {1,4,5}, {2,3,6}};
    int k = 7;

    cout << kthSmallest(test_case, k) << endl;

    return 0;
}
