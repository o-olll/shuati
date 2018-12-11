#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "utils.h"

using namespace std;

string nextClosestTime(string time)
{
    set<char> digits{time[0], time[1], time[3], time[4]};
    string res(time);

    if (time[3] >= time[4]) {
        auto it=upper_bound(digits.begin(), digits.end(), time[3]);
        if (it != digits.end()) {
            res[4] = *it;
            return res;
        }
    } else {
        auto it=upper_bound(digits.begin(), digits.end(), time[3]);
        if (it!=digits.end() && *it<'6') {
            res[3] = *it;
            res[4] = *digits.begin();
            return res;
        }
    }
    res[3] = res[4] = *digits.begin();

    auto it = upper_bound(digits.begin(), digits.end(), time[1]);
    if (it != digits.end()) {
        string t{time[0], *it};
        if (stoi(t) < 24) {
            res[1] = *it;
            return res;
        }
    }

    res[0] = res[1] = *digits.begin();
    return res;
}

int main(int argc, char** argv)
{
    cout << nextClosestTime(argv[1]);

    return 0;
}
