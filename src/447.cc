#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int numberOfBoomerangs(vector<pair<int, int>>& points)
{
    unordered_map<long,int> m;
    int res=0, r;
    long d;
    for (int i=0,j; i<points.size(); ++i) {
        for (j=0; j<points.size(); ++j) {
            auto &p1=points[i], &p2=points[j];
            d = (p1.first-p2.first)*(p1.first-p2.first) +
                (p1.second-p2.second)*(p1.second-p2.second);
            ++m[d];
        }
        for (const auto& p : m) {
            if (p.second > 1) {
                res += p.second*(p.second-1);
            }
        }
        m.clear();
    }
    return res;
}

int main(int argc, char** argv)
{
    vector<pair<int,int>> test_case = {{1,1},{2,2},{3,3}};
    cout << numberOfBoomerangs(test_case);
    return 0;
}
