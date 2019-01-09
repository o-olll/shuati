#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B)
{
    if (A.empty() || A[0].empty() || B.empty() || B[0].empty())
        return {};
    vector<vector<pair<int,int>>> BP(B.size());
    vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));

    for (int i=0,j; i<B.size(); ++i) {
        for (j=0; j<B[0].size(); ++j) {
            if (B[i][j] != 0) {
                BP[i].emplace_back(B[i][j], j);
            }
        }
    }

    for (int i=0,j,k; i<A.size(); ++i) {
        for (k=0; k<A[0].size(); ++k) {
            if (A[i][k] == 0)
                continue;
            for (pair<int,int>& p : BP[k]) {
                res[i][p.second] += A[i][k]*p.first;
            }
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<vector<int>> A = {{1,0,0},{-1,0,3}}, B = {{7,0,0},{0,0,0},{0,0,1}};
    auto res = multiply(A, B);
    for (auto& v : res) {
        utils::printContainer(v.begin(), v.end());
    }

    return 0;
}
