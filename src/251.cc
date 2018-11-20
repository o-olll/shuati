#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        _rowIt = vec2d.begin();
        _matrixEndIt = vec2d.end();
        if (_rowIt != _matrixEndIt)
            _colIt = _rowIt->begin();
    }

    int next() {
        return *_colIt++;
    }

    bool hasNext() {
        while (_rowIt != _matrixEndIt && _colIt == _rowIt->end()) {
            ++_rowIt;
            if (_rowIt == _matrixEndIt) {
                break;
            }
            _colIt = _rowIt->begin();
        }

        return _rowIt != _matrixEndIt;
    }
private:
    vector<vector<int>>::iterator _rowIt, _matrixEndIt;
    vector<int>::iterator _colIt;
};

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{1},{},{2,3},{},{4}};

    Vector2D v2d(test_case);

    int n=0;
    while (v2d.hasNext()) {
        cout << v2d.next() << " ";
    }

    return 0;
}
