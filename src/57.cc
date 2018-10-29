#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

ostream& operator<<(ostream& os, Interval& i) {
    return os << "[" << i.start << "," << i.end << "]";
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
    vector<Interval> res;
    int i;

    for (i=0; i<intervals.size() && intervals[i].end<newInterval.start; ++i) {
        res.push_back(intervals[i]);
    }

    for (; i<intervals.size() && intervals[i].start<=newInterval.end; ++i) {
        newInterval.start = min(newInterval.start, intervals[i].start);
        newInterval.end = max(newInterval.end, intervals[i].end);
    }

    res.push_back(newInterval);

    for (; i<intervals.size(); ++i) {
        res.push_back(intervals[i]);
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<Interval> test_case = {{1,2},{3,5},{6,7},{8,10},{12,16}}, res;

    res = insert(test_case, {4,8});

    utils::printContainer(res.begin(), res.end());

    return 0;
}
