#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int findBlackPixel(vector<vector<char>>& picture, int N) {
    if (picture.empty() || picture[0].empty() || N == 0)
        return 0;

    unordered_map<string,int> rows;
    vector<int> cols(picture[0].size());
    int res = 0;

    for (const auto& v : picture) {
        string line;
        int b = 0;
        for (int i=0; i<v.size(); ++i) {
            if (v[i] == 'B') {
                ++b;
                ++cols[i];
            }
            line.push_back(v[i]);
        }
        if (b == N)
            ++rows[line];
    }

    for (auto& p : rows) {
        if (p.second == N) {
            for (int i=0; i<p.first.size(); ++i) {
                if (p.first[i] == 'B' && cols[i] == N)
                    res += N;
            }
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<vector<char>> test_case = {{'W', 'B', 'W', 'B', 'B', 'W'},
                                      {'W', 'B', 'W', 'B', 'B', 'W'},
                                      {'W', 'B', 'W', 'B', 'B', 'W'},
                                      {'W', 'B', 'B', 'W', 'B', 'W'}};

    cout << findBlackPixel(test_case, 3) << endl;

    return 0;
}
