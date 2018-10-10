#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k)
{
    int l, r, res;
    unordered_map<char, int> counts;
    char c;

    l = r = res = 0;

    for (r=0; r<s.size(); ++r) {
        ++counts[s[r]];
        if (counts.size() > k) {
            res = max(res, r-l);
            while (counts.size() > k) {
                c = s[l++];
                --counts[c];
                if (counts[c] == 0)
                    counts.erase(c);
            }
        }
    }

    return max(res, r-l);
}

int main(int argc, char** argv)
{
    string test_case(argv[1]);
    int k = atoi(argv[2]);

    cout << lengthOfLongestSubstringKDistinct(test_case, k) << endl;

    return 0;
}
