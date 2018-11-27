#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited)
{
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int countComponents(int n, vector<pair<int, int> >& edges)
{
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    int res = 0;

    for (const auto& p : edges) {
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }

    for (int i=0; i<n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            ++res;
        }
    }

    return res;
}

int getRoot(vector<int>& roots, int a)
{
    while (roots[a] != -1) {
        a = roots[a];
    }
    return a;
}

int countComponentsUnionFind(int n, vector<pair<int, int> >& edges)
{
    vector<int> roots(n, -1);
    int a, b;

    for (const auto& edge : edges) {
        a = getRoot(roots, edge.first);
        b = getRoot(roots, edge.second);
        if (a != b) {
            --n;
            roots[a] = roots[b];
        }
    }

    return n;
}

int main(int argc, char** argv)
{
    vector<pair<int,int>> test_case = {{0,1},{1,2},{2,3}};

    cout << countComponentsUnionFind(5, test_case) << endl;

    return 0;
}
