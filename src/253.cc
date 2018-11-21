#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "utils.h"

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
    Interval(): Interval(0, 0) {}
};

int minMeetingRooms(vector<Interval>& intervals)
{
    map<int,int> meetings;

    for (Interval iv : intervals) {
        ++meetings[iv.start];
        --meetings[iv.end];
    }

    int res = 0, n = 0;

    for (auto& p : meetings) {
        n += p.second;
        res = max(res, n);
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    return 0;
}
