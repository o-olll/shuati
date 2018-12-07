#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool validWordSquare(vector<string>& words)
{
    int i, j, last = INT_MAX;
    for (i=0; i<words.size(); ++i) {
        if (words[i].size()>last || words[i].size()>words.size() ||
            words[words[i].size()-1].size()<i+1)
            return false;
        last = words[i].size();
        for (j=i; j<words[i].size(); ++j) {
            if (words[i][j] != words[j][i])
                return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"abcde",
                                "bnrt",
                                "crcy",
                                "dtyx",
                                "e"};

    cout << boolalpha << validWordSquare(test_case) << endl;

    return 0;
}
