#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool compareString(const string& s1, const string& s2, pair<char,char>& res)
{
    int i=0, j=0;

    while (i<s1.size() && j<s2.size()) {
        if (s1[i] != s2[j]) {
            res.first = s1[i];
            res.second = s2[j];
            return true;
        }
        ++i;
        ++j;
    }

    return false;
}

bool dfs(vector<vector<char>>& graph, char src, vector<bool>& visited, vector<bool>& visitedOnPath, string& res)
{
    if (visited[src-'a'])
        return true;

    visited[src-'a'] = true;

    for (char neighbor : graph[src-'a']) {
        if (visitedOnPath[neighbor-'a'])
            return false;
        visitedOnPath[neighbor-'a'] = true;
        if (!dfs(graph, neighbor, visited, visitedOnPath, res))
            return false;
        visitedOnPath[neighbor-'a'] = false;
    }

    res.push_back(src);
    return true;
}

string alienOrder(vector<string>& words)
{
    vector<vector<char>> graph(26);
    vector<bool> visited(26, false), visitedOnPath = visited;
    string res;

    // build graph
    for (int i=1; i<words.size(); ++i) {
        pair<char,char> p;
        if (compareString(words[i-1], words[i], p))
            graph[p.second-'a'].push_back(p.first);
    }

    // topological sort
    for (char c='a'; c<='z'; ++c) {
        if (graph[c-'a'].empty())
            continue;
        visitedOnPath[c-'a'] = true;
        if (!dfs(graph, c, visited, visitedOnPath, res))
            return "";
        visitedOnPath[c-'a'] = false;
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<string> words = {"wrt",
                            "wrf",
                            "er",
                            "ett",
                            "rftt",
                            "zxf",
                            "fxf"};

    cout << alienOrder(words) << endl;

    return 0;
}
