#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool isOneEditDistance(string s, string t)
{
    int m, n;
    bool changed = false;

    m = s.size();
    n = t.size();

    if (m-n>1 || n-m>1)
        return false;

    if (m-n == 1) {
        for (int p=0,q=0; p<m && q<n; ++p) {
            if (s[p] != t[q]) {
                if (changed)
                    return false;
                changed = true;
            } else {
                ++q;
            }
        }
        return true;
    } else if (m-n == -1) {
        return isOneEditDistance(t, s);
    }

    for (int p=0,q=0; p<m; ++p,++q) {
        if (s[p] != t[q]) {
            if (changed)
                return false;
            changed = true;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    cout << boolalpha << isOneEditDistance(argv[1], argv[2]);

    return 0;
}
