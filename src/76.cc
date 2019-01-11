#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

string minWindow(string s, string t)
{
    unordered_map<char, int> m;
    int l=0, r=0, len=INT_MAX, minL=0, minR=0, count=0;
    char c;

    for (char c : t)
        ++m[c];

    for (r=0; r<s.size(); ++r) {
        c = s[r];
        if (--m[c] >= 0)
            ++count;

        while (count == t.size()) {
            if (r-l+1 < len) {
                minL = l;
                minR = r;
                len = r-l+1;
            }
            if (++m[s[l]] > 0)
                --count;
            ++l;
        }
    }
    return len==INT_MAX ? "" : string(s.begin()+minL, s.begin()+minR+1);
}

int main(int argc, char** argv)
{
    cout << minWindow(argv[1], argv[2]);

    return 0;
}
