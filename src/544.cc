#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

string findContestMatch(int n)
{
    vector<string> v;

    for (int i=1; i<=n; ++i) {
        v.push_back(to_string(i));
    }

    while (n > 1) {
        n /= 2;
        vector<string> tmp;
        for (int i=0; i<n; ++i) {
            tmp.push_back("("+v[i]+","+v[v.size()-i-1]+")");
        }

        v.swap(tmp);
    }

    return v[0];
}

int main(int argc, char** argv)
{
    cout << findContestMatch(atoi(argv[1])) << endl;
    return 0;
}
