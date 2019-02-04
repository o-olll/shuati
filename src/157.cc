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
        char* buffer4 = (char*) malloc(4*sizeof(char));

        while (res < n && r == 4) {
            r = read4(buffer4);
            len = min(n-res, r);
            memcpy(buf+res, buffer4, len);
            res += len;
        }

        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    char* buf = (char*) malloc(atoi(argv[1]) * sizeof(char));
    int res = sol.read(buf, atoi(argv[1]));
    printf("%d\n", res);
    for (int i=0; i<res; ++i) {
        printf("%c ", *buf++);
    }
    return 0;
}
