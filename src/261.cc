#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int getRoot(int n, vector<int>& roots)
{
    while (roots[n] != -1) {
        n = roots[n];
    }
    return n;
}

bool validTree(int n, vector<pair<int, int>>& edges)
{
    if (edges.size() != n-1)
        return false;

    vector<int> roots(n, -1);
    int a, b;

    for (auto& p: edges) {
        a = getRoot(p.first, roots);
        b = getRoot(p.second, roots);
        if (a == b)
            return false;
        roots[a] = b;
    }
    return true;
}

int main(int argc, char** argv)
{
    vector<pair<int,int>> test_case = {{0, 1}, {1, 2}, {2, 0}, {4, 3}};
    cout << boolalpha << validTree(5, test_case) << endl;

    return 0;
}
