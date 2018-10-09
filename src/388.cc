#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int lengthLongestPath(string input)
{
    istringstream iss(input);
    string line;
    unordered_map<int,int> counts;
    int res = 0;

    while (getline(iss, line)) {
        int t = line.find_last_of('\t') + 1;
        int remain = line.size() - t;

        if (line.find('.') != string::npos) {
            res = max(res, remain+counts[t-1]);
        } else {
            counts[t] = remain + counts[t-1] + 1;
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    string test(argv[1]);
    cout << test << endl;
    cout << lengthLongestPath(test) << endl;

    return 0;
}
