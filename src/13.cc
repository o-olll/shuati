#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int res = 0;
    for (int i=0; i<s.size(); ++i) {
        if (i+1<s.size() && m[s[i]]<m[s[i+1]])
            res -= m[s[i]];
        else
            res += m[s[i]];
    }
    return res;
}

int main(int argc, char** argv)
{
    cout << romanToInt(argv[1]) << endl;

    return 0;
}
