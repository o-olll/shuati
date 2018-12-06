#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int numWays(int n, int k)
{
    if (n == 0)
        return 0;
    if (k < 2)
        return n<3;

    int same = 0, diff = k, t;
    for (int i=1; i<n; ++i) {
        t = same;
        same = diff;
        diff = (t+diff) * (k-1);
    }

    return same + diff;
}

int main(int argc, char** argv)
{
    return 0;
}
