#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

#define I(x, y) x*N + y

using namespace std;

int M, N;
vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int getRoot(vector<int>& oneDimMap, int index)
{
    while (oneDimMap[index] != index)
        index = oneDimMap[index];
    return index;
}

void addLand(vector<int>& oneDimMap, int& islands, pair<int,int> position)
{
    int r, c, index, x, y, neighborRoot;

    r = position.first;
    c = position.second;

    index = I(r, c);
    if (oneDimMap[index] != -1)
        return;

    oneDimMap[index] = index;
    ++islands;

    for (auto dir : dirs) {
        x = dir.first + r;
        y = dir.second + c;
        if (x<0 || x>=M || y<0 || y>=N || oneDimMap[I(x,y)] == -1)
            continue;
        neighborRoot = getRoot(oneDimMap, I(x, y));
        if (neighborRoot != index) {
            --islands;
            oneDimMap[index] = neighborRoot;
            index = neighborRoot;
        }
    }
}

vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions)
{
    vector<int> oneDimMap(m*n, -1), res;
    int islands = 0;

    M = m;
    N = n;

    for (auto& position : positions) {
        printf("%d %d: ", position.first, position.second);
        addLand(oneDimMap, islands, position);
        res.push_back(islands);
        cout << islands << endl;
    }

    return res;
}



int main(int argc, char** argv)
{
    vector<pair<int,int>> test_case = {{0,1},{2,1},{0,2}, {2,2}, {1,1}, {1,2}};
    auto res = numIslands2(3, 3, test_case);

    for (int i=0; i<test_case.size(); ++i) {
        //        printf("%d %d; %d\n", test_case[i].first, test_case[i].second, res[i]);
    }

    return 0;
}
