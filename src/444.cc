#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "utils.h"

using namespace std;

bool topoSort(unordered_map<int, unordered_set<int>>& graph,
              unordered_set<int>& seen,
              unordered_set<int>& seenOnPath,
              vector<int>& res, int node);

bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs)
{
    unordered_map<int, unordered_set<int>> graph;
    unordered_set<int> seen, seenOnPath;
    vector<int> sorted;

    // construct graph
    for (auto &v : seqs) {
        for (int i=v.size()-1; i>0; --i) {
            graph[v[i]].insert(v[i-1]);
        }
    }

    // topological sort
    for (auto it=graph.begin(); it!=graph.end(); ++it) {
        if (!topoSort(graph, seen, seenOnPath, sorted, it->first))
            return false;
    }

    utils::printContainer(sorted.begin(), sorted.end());

    // examine
    // uniqueness
    for (int i=sorted.size()-1; i>0; --i) {
        if (!graph[sorted[i]].count(sorted[i-1])) {
            return false;
        }
    }
    // compare with org
    if (org.size() != sorted.size())
        return false;

    for (int i=0; i<org.size(); ++i) {
        if (org[i] != sorted[i])
            return false;
    }

    return true;
}

bool topoSort(unordered_map<int, unordered_set<int>>& graph,
              unordered_set<int>& seen,
              unordered_set<int>& seenOnPath,
              vector<int>& res,
              int node)
{
    if (seenOnPath.count(node))
        return false;
    if (seen.count(node))
        return true;

    seen.insert(node);
    seenOnPath.insert(node);
    for (auto& neighbor : graph[node]) {
        if (!topoSort(graph, seen, seenOnPath, res, neighbor))
            return false;
    }
    seenOnPath.erase(node);
    res.push_back(node);
    return true;
}

int main(int argc, char** argv)
{
    vector<int> org = {4,1,5,2,6,3};
    vector<vector<int>> seqs = {{5,2,6,3},{4,1,2,3}};

    cout << boolalpha << sequenceReconstruction(org, seqs) << endl;

    return 0;
}
