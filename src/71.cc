#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <string>
#include "utils.h"

using namespace std;

string simplifyPath(string path)
{
    stack<string> dirs;
    istringstream iss(path);
    string dir, res;

    while (getline(iss, dir, '/')) {
        if (dir.empty() || dir == ".")
            continue;
        if (dir == "..") {
            if (!dirs.empty())
                dirs.pop();
        } else {
            dirs.push(dir);
        }
    }

    while (!dirs.empty()) {
        res = "/" + dirs.top() + res;
        dirs.pop();
    }

    return res.empty() ? "/" : res;
}

int main(int argc, char** argv)
{
    cout << simplifyPath(argv[1]);

    return 0;
}
