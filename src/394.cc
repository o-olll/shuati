#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "utils.h"

using namespace std;

// 3[a2[c]] -> accaccacc

string decodeString(string s)
{
    string t, current;
    int n = 0;
    stack<string> strs;
    stack<int> nums;

    for (char c : s) {
        if (isdigit(c)) {
            n = n*10 + c-'0';
        } else {
            if (isalpha(c)) {
                current.push_back(c);
            } else if (c == '[') {
                strs.push(current);
                nums.push(n);
                current = "";
                n = 0;
            } else if (c == ']') {
                n = nums.top();
                nums.pop();
                while (n-- > 0) {
                    t.append(current);
                }
                current = strs.top() + t;
                strs.pop();
                t = "";
            }
        }
    }
    return current;
}

int main(int argc, char** argv)
{
    cout << decodeString(argv[1]) << endl;

    return 0;
}
