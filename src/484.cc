#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<int> findPermutation(string s)
{
    vector<int> res;

    for (int i=0,j=0; i<s.size()+1; ++i) {
        if (s[i] == 'I' || i == s.size()) {
            for (j=i+1; res.size()<i+1; --j)
                res.push_back(j);
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<int> res = findPermutation(argv[1]);

    utils::printContainer(res.begin(), res.end());

    return 0;
}
