#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "utils.h"

using namespace std;

class StringIterator {
public:
    StringIterator(string compressedString):
        _iss(compressedString),
        _n(0),
        _c('\0')
    {
    }

    char next() {
        --_n;
        return _c;
    }

    bool hasNext() {
        if (_n > 0)
            return true;
        if (!(_iss >> _c >> _n))
            return false;
        return hasNext();
    }

private:
    istringstream _iss;
    int _n;
    char _c;
};

int main(int argc, char** argv)
{
    StringIterator strIter(argv[1]);

    while (strIter.hasNext()) {
        printf("%c ", strIter.next());
    }

    return 0;
}
