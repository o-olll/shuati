#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

class ZigzagIterator {
    using VecIter = vector<int>::iterator;
    using ListIter = list<pair<VecIter, VecIter>>::iterator;
public:
    ZigzagIterator(vector<vector<int>>& vectors) {
        for (vector<int>& v : vectors) {
            if (v.begin() != v.end())
                _iters.emplace_back(v.begin(), v.end());
        }
        _curr = _iters.begin();
        cout << _iters.size() << endl;
    }

    int next() {
        int res = *(_curr->first);
        ListIter it = _curr;
        ++_curr;

        ++(it->first);
        if (it->first == it->second) {
            _iters.erase(it);
        }

        if (_curr == _iters.end())
            _curr = _iters.begin();

        return res;
    }

    bool hasNext() {
        return !_iters.empty();
    }

private:
    list<pair<VecIter, VecIter>> _iters;
    ListIter _curr;
};

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{4,6,0}, {2}, {}, {1,5,7,8}};

    ZigzagIterator zIter(test_case);

    while (zIter.hasNext()) {
        cout << zIter.next() << endl;
    }

    return 0;
}
