#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

void removeImp(string s, int start, int r, vector<string>& res, vector<char> p);

vector<string> removeInvalidParentheses(string s)
{
    vector<string> res;
    removeImp(s, 0, 0, res, {'(', ')'});
    return res;
}

void removeImp(string s, int start, int r, vector<string>& res, vector<char> p)
{
    int i, j, count;

    for (i=start,count=0; i<s.size() && count>=0; ++i) {
        if (s[i] == p[0]) ++ count;
        else if (s[i] == p[1]) --count;
        if (count < 0)
            break;
    }

    if (i < s.size()) {
        for (j=r; j<=i; ++j) {
            if (s[j]==p[1] && (j==0 || s[j-1]!=p[1]))
                removeImp(s.substr(0, j)+s.substr(j+1), i, j, res, p);
        }
        return;
    }

    reverse(s.begin(), s.end());
    if (p[0] == '(')
        removeImp(s, 0, 0, res, {')', '('});
    else
        res.push_back(s);
}

int main(int argc, char** argv)
{
    auto res = removeInvalidParentheses(argv[1]);
    cout << "result: " << endl;
    for (string& s : res) {
        cout << s << endl;
    }
    return 0;
}
