#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "utils.h"

using namespace std;

void getPermutatation(string& permutate, int n, unordered_set<string>& res);

vector<string> generatePalindromes(string s)
{
    unordered_map<char,int> chars;
    vector<string> res;
    unordered_set<string> permutations;
    string permutate;
    char odd = '\0';

    for (char c : s)
        ++chars[c];

    for (const auto& p : chars) {
        if (p.second%2 == 1) {
            if (odd != '\0')
                return res;
            odd = p.first;
        }
        permutate.append(p.second/2, p.first);
    }

    getPermutatation(permutate, permutate.size(), permutations);

    for (string s : permutations) {
        permutate = s;
        reverse(permutate.begin(), permutate.end());
        if (odd != '\0')
            s.push_back(odd);
        s.append(permutate);
        res.push_back(s);
    }
    return res;
}

void getPermutatation(string& permutate, int n, unordered_set<string>& res)
{
    if (n <= 1) {
        res.insert(permutate);
        return;
    }
    for (int i=0; i<n-1; ++i) {
        getPermutatation(permutate, n-1, res);
        if ((n&1) == 0) {
            swap(permutate[i], permutate[n-1]);
        } else {
            swap(permutate[0], permutate[n-1]);
        }
    }
    getPermutatation(permutate, n-1, res);
}

int main(int argc, char** argv)
{
    vector<string> res = generatePalindromes(argv[1]);

    utils::printContainer(res.begin(), res.end());
    return 0;
}
