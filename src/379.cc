#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "utils.h"

using namespace std;

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers): _nums(maxNumbers), _used(maxNumbers, false) {
        _next = 0;
        _rid = -1;
        _cap = maxNumbers;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (_rid==-1 && _next==_cap)
            return -1;
        if (_rid >= 0) {
            int res = _nums[_rid--];
            _used[res] = true;
            return res;
        }
        _used[_next] = true;
        return _next++;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return number>=0 && number<_cap && !_used[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (number>=0 && number<_cap && _used[number]) {
            _used[number] = false;
            _nums[++_rid] = number;
        }
    }

private:
    vector<int> _nums;
    vector<bool> _used;
    int _next, _rid, _cap;
};

int main(int argc, char** argv)
{
    PhoneDirectory pd(atoi(argv[1]));

    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
        string cmd;
        iss >> cmd;
        if (cmd == "get" || cmd == "g")
            cout << pd.get() << endl;
        else if (cmd == "check" || cmd == "c") {
            int n;
            iss >> n;
            cout << boolalpha << pd.check(n) << endl;
        } else if (cmd == "release" || cmd == "r") {
            int n;
            iss >> n;
            pd.release(n);
        }
    }

    cout << "Hello world" << endl;
    
    return 0;
}
