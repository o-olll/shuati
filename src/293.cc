#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<string> generatePossibleNextMoves(string s)
{
    if (s.size() < 2)
        return vector<string>();

    vector<string> res;

    for (int i=0; i<s.size()-1; ++i) {
        if (s[i]=='+' && s[i+1]=='+') {
            s[i] = s[i+1] = '-';
            res.push_back(s);
            s[i] = s[i+1] = '+';
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<string> res = generatePossibleNextMoves(argv[1]);

    for (string& s : res)
        cout << s << endl;

    return 0;
}
