#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

void removeImp(string s, int level, int lToRemove, int rToRemove, vector<string>& res);

vector<string> removeInvalidParentheses(string s)
{
    int lToRemove=0, rToRemove=0, l=0;
    vector<string> res;

    for (char c : s) {
        if (c == '(')
            ++l;
        if (c == ')') {
            if (l > 0) {
                --l;
            } else {
                ++rToRemove;
            }
        }
    }
    lToRemove = l;

    removeImp(s, 0, lToRemove, rToRemove, res);
    return res;
}

bool isValid(const string& s)
{
    int l=0;
    for (char c : s) {
        if (c == '(')
            ++l;
        if (c ==')') {
            if (l <= 0)
                return false;
            --l;
        }
    }
    return l == 0;
}

void removeImp(string s, int level, int lToRemove, int rToRemove, vector<string>& res)
{
    //    printf("%-12s level=%d lToRemove=%d rToRemove=%d\n", s.c_str(), level, lToRemove, rToRemove);
    if (lToRemove==0 && rToRemove==0) {
        if (isValid(s)) {
            res.push_back(s);
        }
        return;
    }

    for (int i=level; i<s.size(); ++i) {
        if (i!=0 && s[i]==s[i-1]) continue;
        if (s[i]=='(' && lToRemove>0) {
            removeImp(s.substr(0,i)+s.substr(i+1), i, lToRemove-1, rToRemove, res);
        }
        if (s[i]==')' && rToRemove>0) {
            removeImp(s.substr(0,i)+s.substr(i+1), i, lToRemove, rToRemove-1, res);
        }
    }
}

int main(int argc, char** argv)
{
    auto res = removeInvalidParentheses(argv[1]);

    for (string& s : res) {
        cout << s << endl;
    }
    return 0;
}
