#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters)
{
    long d, md, i, j;

    md = 0;

    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    for (i=0,j=0; i<houses.size(); ++i) {
        d = LONG_MAX;
        while (j<heaters.size() && houses[i]>heaters[j])
            ++j;
        if (j > 0)
            d = min(d, (long)houses[i]-heaters[j-1]);
        if (j < heaters.size())
            d = min(d, (long)heaters[j]-houses[i]);
        md = max(md, d);
    }

    return md;
}

int main(int argc, char** argv)
{
    vector<int> houses = {25,510},
        heaters = {771,357,44,927,952};

    cout << findRadius(houses, heaters) << endl;

    return 0;
}
