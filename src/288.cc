#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "utils.h"

using namespace std;

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto word : dictionary) {
            string abbr = getAbbr(word);
            _map[abbr].insert(word);
        }
    }

    bool isUnique(string word) {
        string abbr = getAbbr(word);
        auto it = _map.find(abbr);
        return it == _map.end() || it->second.count(abbr) == it->second.size();
    }

private:
    string getAbbr(string s) {
        if (s.size() < 4)
            return s;
        return string(1,s.front()) + to_string(s.size()-2) + string(1,s.back());
    }
    unordered_map<string, unordered_set<string>> _map;
};

int main(int argc, char** argv)
{
    vector<string> test_case = {"deer", "door", "cake", "card"};

    ValidWordAbbr a(test_case);
    cout << boolalpha << a.isUnique(argv[1]) << endl;

    return 0;
}
