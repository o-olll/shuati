#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int maxEnvelopes(vector<pair<int, int>>& envelopes)
{
    vector<int> sorted;

    sort(envelopes.begin(), envelopes.end(), [] (const pair<int,int>& p1, const pair<int,int>& p2) {
                                                 return (p1.first==p2.first && p1.second>p2.second) ||
                                                     p1.first<p2.first; });

    for (const auto& p : envelopes) {
        auto it = lower_bound(sorted.begin(), sorted.end(), p.second);
        if (it == sorted.end()) {
            sorted.push_back(p.second);
        } else {
            *it = p.second;
        }
    }
    return sorted.size();
}

int main(int argc, char** argv)
{
    vector<pair<int,int>> test_case = {{4,5},{4,6},{6,6},{2,3},{1,1}};
    cout << maxEnvelopes(test_case);

    return 0;
}
