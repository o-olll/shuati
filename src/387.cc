#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int firstUniqChar(string s)
{
    vector<pair<int,int>> m(26);
    int p = s.size();
    for (int i=0; i<s.size(); ++i) {
        m[s[i]-'a'].first++;
        m[s[i]-'a'].second = i;
    }
    for (int i=0; i<m.size(); ++i) {
        if (m[i].first==1 && m[i].second<p) {
            p = m[i].second;
        }
    }
    return p==s.size()? -1 : p;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    return 0;
}
