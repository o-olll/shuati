#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

string test_case = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int p = 0;

int read4(char *buf)
{
    string s = test_case.substr(p, 4);
    p += s.size();
    memcpy(buf, s.c_str(), s.size());
    return s.size();
}

class Solution {
public:
    int read(char *buf, int n) {
        int res = 0, r = 4, len;

        while (res < n && r == 4) {
            if (rp == bufLen) {
                r = read4(buffer4);
                bufLen = r;
                rp = 0;
            }
            len = min(n-res, bufLen-rp);
            memcpy(buf+res, buffer4+rp, len);
            rp += len;
            res += len;
        }

        return res;
    }

private:
    char buffer4[4];
    int rp = 0, bufLen = 0;
};

int main(int argc, char** argv)
{
    Solution sol;
    int n;

    printf("*Enter: ");
    while (cin >> n) {
        char* buf = (char*) malloc(n * sizeof(char));
        int res = sol.read(buf, n);
        printf("[%d] ", res);
        for (int i=0; i<res; ++i) {
            printf("%c ", *buf++);
        }
        printf("\n*Enter: ");
    }

    return 0;
}
