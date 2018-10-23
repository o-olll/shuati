#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

string minWindow(string S, string T)
{
    int i, j, start, end, len;

    i = j = 0;
    len = INT_MAX;
    start = -1;

    while (i < S.size()) {
        if (S[i] == T[j]) {
            if (j == T.size() - 1) {
                end = i + 1;

                // move j to 0, and i to next
                while (j >= 0) {
                    if (S[i] == T[j])
                        --j;
                    --i;
                }
                ++i;

                // update len
                if (end - i < len) {
                    len = end - i;
                    start = i;
                }
            }
            ++j;
        }
        ++i;
    }

    return start == -1 ? "" : S.substr(start, len);
}

int main(int argc, char** argv)
{

    cout << minWindow(argv[1], argv[2]) << endl;

    return 0;
}
