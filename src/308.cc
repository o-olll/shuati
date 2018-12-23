#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        mat.resize(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        bit.resize(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));

        for (int i=0,j; i<matrix.size(); ++i) {
            for (j=0; j<matrix[i].size(); ++j) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int diff = val - mat[row+1][col+1];
        mat[row+1][col+1] = val;
        for (int i=row+1,j; i<mat.size(); i+=(i&-i)) {
            for (j=col+1; j<mat[0].size(); j+=(j&-j)) {
                bit[i][j] += diff;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2,col2) - getSum(row1-1,col2) - getSum(row2,col1-1) + getSum(row1-1,col1-1);
    }

    int getSum(int row, int col) {
        int res = 0;
        for (int i=row+1,j; i>0; i-=(i&-i)) {
            for (j=col+1; j>0; j-=(j&-j)) {
                res += bit[i][j];
            }
        }
        return res;
    }

private:
    vector<vector<int>> mat;
    vector<vector<int>> bit;
};

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{3, 0, 1, 4, 2},
                                     {5, 6, 3, 2, 1},
                                     {1, 2, 0, 1, 5},
                                     {4, 1, 0, 1, 7},
                                     {1, 0, 3, 0, 5}};

    NumMatrix mat(test_case);
    int r1, c1, r2, c2, v;
    string cmd;
    cout << "Coordinates: ";
    while (cin >> r1 >> c1 >> r2 >> c2) {
        cout << mat.sumRegion(r1,c1,r2,c2) << endl;
        cout << "Update? ";
        cin >> cmd;
        if (cmd == "y") {
            cout << "Coordinate and value: ";
            int r, c;
            cin >> r >> c >> v;
            mat.update(r, c, v);
            cout << mat.sumRegion(r1,c1,r2,c2) << endl;
        }
        cout << "Coordinates: ";
    }
    return 0;
}
