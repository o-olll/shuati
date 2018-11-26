#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n):
        _rows(n, 0), _cols(n, 0), _diags(2, 0), _n(n)
    {
    }

    int move(int row, int col, int player) {
        int add = player==1? 1 : -1;
        _rows[row] += add;
        _cols[col] += add;
        if (row == col)
            _diags[0] += add;
        if (row+col == _n-1)
            _diags[1] += add;
        if (abs(_rows[row])==_n || abs(_cols[col])==_n ||
            abs(_diags[0])==_n || abs(_diags[1])==_n)
            return player;
        return 0;
    }

private:
    vector<int> _rows, _cols, _diags;
    int _n;
};

int main(int argc, char** argv)
{
    int p = 1, res = 0, r, c;
    TicTacToe t(atoi(argv[1]));

    while (res == 0) {
        cin >> r >> c;
        res = t.move(r, c, p);
        p = 3-p;
    }

    cout << res << endl;

    return 0;
}
