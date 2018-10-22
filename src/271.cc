#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

string encode(vector<string>& strs)
{
    string res;

    for (string& s : strs) {
        res.append(to_string(s.size()) + "/" + s);
    }

    return res;
}

vector<string> decode(string s)
{
    vector<string> res;
    int i = 0, n = 0;

    while (i < s.size()) {
        if (isdigit(s[i]))
            n = n*10 + s[i++] - '0';
        else if (s[i] == '/') {
            res.push_back(s.substr(++i, n));
            i += n;
            n = 0;
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"/", "1/2", "3/4", "5/6", " ", " ", "7/890", "0/0", " ", " /////"};

    string encoded = encode(test_case);
    cout << encoded << endl;

    vector<string> decoded = decode(encoded);
    utils::printContainer(decoded.begin(), decoded.end());
    cout << boolalpha << (decoded == test_case) << endl;

    return 0;
}
