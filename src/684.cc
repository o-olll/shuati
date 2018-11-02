#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int root(vector<int>& roots, int v) {
    while (roots[v] != v)
        v = roots[v];
    return v;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges)
{
    vector<int> roots(edges.size()+1);
    int u, v;

    for (int i=0; i<roots.size(); ++i)
        roots[i] = i;

    for (vector<int>& edge : edges) {
        u = root(roots, edge[0]);
        v = root(roots, edge[1]);
        if (u == v)
            return edge;
        roots[u] = roots[v];
    }

    return {-1,-1};
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{2,3},{5,4},{1,2},{2,4},{4,3}};

    vector<int> res = findRedundantConnection(test_case);

    printf("%d %d\n", res[0], res[1]);
    return 0;
}
