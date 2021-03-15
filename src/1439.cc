#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include "utils.h"

using namespace std;

int kthSmallest(vector<vector<int>>& mat, int k) {
    if (mat.empty() || mat[0].empty() || k==0)
        return INT_MIN;

    priority_queue<int> pq;
    int col = min(k, (int)(mat[0].size()));

    pq.push(0);
    for (const auto& row : mat) {
        priority_queue<int> new_pq;
        while (!pq.empty()) {
            for (int i=0; i<col; ++i) {
                new_pq.push(pq.top() + row[i]);
                if (new_pq.size() > k) {
                    new_pq.pop();
                }
            }
            pq.pop();
        }
        pq.swap(new_pq);
    }

    return pq.top();
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{1,10,10}, {1,4,5}, {2,3,6}};
    int k = 7;

    cout << kthSmallest(test_case, k) << endl;

    return 0;
}
