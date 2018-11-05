#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "utils.h"

using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        int s, e;
        set<pair<int,int>> overlaps;
        for (auto& event : events) {
            s = max(start, event.first);
            e = min(end, event.second);
            if (s < e) {
                if (!canBook(overlaps, s, e))
                    return false;
                overlaps.emplace(s, e);
            }
        }
        events.emplace_back(start, end);
        return true;
    }

private:
    bool canBook(set<pair<int,int>>& s, int start, int end) {
        auto it = s.lower_bound({start, end});
        if (it!=s.end() && end>it->first) return false;
        if (it!=s.begin() && start<(--it)->second) return false;
        s.emplace(start, end);
        return true;
    }

    vector<pair<int,int>> events;
};


int main(int argc, char** argv)
{
    int start, end;
    MyCalendarTwo calendar;

    while (cin >> start >> end && start>=0 && end>=0) {
        cout << boolalpha << calendar.book(start, end) << endl;
    }

    return 0;
}
