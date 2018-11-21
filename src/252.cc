#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
    Interval(): Interval(0, 0) {}
};

bool canAttendMeetings(vector<Interval>& intervals)
{
    sort(intervals.begin(), intervals.end(),
         [](const Interval& i1, const Interval& i2) {
             return i1.start < i2.start;
         });

    Interval current;

    for (Interval& interval : intervals) {
        if (interval.start < current.end)
            return false;
        current = interval;
    }

    return true;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    return 0;
}
