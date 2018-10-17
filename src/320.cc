#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

void generateImp(string word, int start, vector<string>& res);

vector<string> generateAbbreviations(string word)
{
    vector<string> res{"word"};
    generateImp(word, 0, res);
    return res;
}

void generateImp(string word, int start, vector<string>& res)
{
    int i, j; // i: pos of letters, j: pos of digits

    for (i=start; i<word.size(); ++i) {
        for (j=i+1; j<=word.size(); ++j) {
            string next = word.substr(start, i-start) + to_string(j-i) + word.substr(j);
            res.push_back(next);
            generateImp(next, i+1+to_string(j-i).size(), res);
        }
    }
}

int main(int argc, char** argv)
{
    vector<string> res = generateAbbreviations(argv[1]);

    cout << res.size() << endl;
    utils::printContainer(res.begin(), res.end());

    return 0;
}
