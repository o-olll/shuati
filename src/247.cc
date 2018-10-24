#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<string> findStrobogrammatic(int n)
{
    vector<string> res;
    int i;

    if (n%2 == 1)
        res = {"0", "1", "8"};
    else
        res = {""};

    for (i=0; i<n/2; ++i) {
        vector<string> t;
        for (string s : res) {
            if (i != n/2 - 1)
                t.push_back("0" + s + "0");
            t.push_back("1" + s + "1");
            t.push_back("8" + s + "8");
            t.push_back("6" + s + "9");
            t.push_back("9" + s + "6");
        }
        res = t;
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<string> res = findStrobogrammatic(atoi(argv[1]));

    cout << "Count: " << res.size() << endl;
    utils::printContainer(res.begin(), res.end());

    return 0;
}
