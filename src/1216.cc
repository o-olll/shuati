#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;
int YES = 2;
int NO = 1;
int INIT = 0;

bool isValidImp(const string& s, int l, int r, int k, vector<vector<int>>& mem);

bool isValidPalindrome(const string& s, int k)
{
    vector<vector<int>> mem(s.size(), vector<int>(s.size(), INIT));
    return isValidImp(s, 0, s.size()-1, k, mem);
}

bool isValidImp(const string& s, int l, int r, int k, vector<vector<int>>& mem) {
    if (k < 0)
        return false;
    if (r <= l)
        return true;
    if (mem[r][l] != INIT)
        return mem[r][l] == YES;

    int res = INIT;

    if (s[l] == s[r]) {
        res = isValidImp(s, l+1, r-1, k, mem);
    } else {
        res = isValidImp(s, l+1, r, k-1, mem) || isValidImp(s, l, r-1, k-1, mem);
    }

    mem[r][l] = res;

    return res;
}

int main(int argc, char** argv)
{
    string s = "abczyxba";
    int k = 2;
    cout << std::boolalpha << isValidPalindrome(s, k) << endl;
    return 0;
}
