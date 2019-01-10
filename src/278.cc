#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int firstBadVersion(int n)
{
    int l=1, r=n, m;

    while (l < r) {
        m = l + (r-l)/2;
        if (isBadVersion(m))
            r = m;
        else
            l = m + 1;
    }

    return l;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    return 0;
}
