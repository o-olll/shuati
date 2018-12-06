#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include "utils.h"

using namespace std;

class MovingAverage {
public:
    MovingAverage(int size)
        :_cap(size),
         _sum(0)
    {
    }

    double next(int val) {
        if (_q.size() == _cap) {
            _sum -= _q.front();
            _q.pop();
        }
        _q.push(val);
        _sum += val;
        return _sum / _q.size();
    }

private:
    queue<int> _q;
    int _cap;
    double _sum;
};

int main(int argc, char** argv)
{
    MovingAverage ma(atoi(argv[1]));
    int val;
    while (cin >> val) {
        cout << ma.next(val) << endl;
    }
    return 0;
}
