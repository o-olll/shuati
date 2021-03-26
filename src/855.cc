#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
#include "utils.h"

using namespace std;

struct Interval {
    int l;
    int r;
    inline static int LEN;
    
    Interval(int l, int r): l(l), r(r) {}
    int getDist() const {
        if (l == 0)
            return r;
        if (r == LEN-1)
            return LEN-1-l;
        return (r - l) / 2;
    }
    int getSeat() const {
        if (l == 0)
            return 0;
        if (r == LEN-1)
            return LEN-1;
        return l + (r - l) / 2;
    }
    
    bool operator<(const Interval& other) const {
        return getDist() > other.getDist() or (getDist() == other.getDist() && l < other.l);
    }
};

class ExamRoom {
public:
    ExamRoom(int N) {
        LEN = N;
        Interval::LEN = N;
        intervals.emplace(0, N-1);
    }
    
    int seat() {
        Interval interval = *(intervals.begin());
        intervals.erase(intervals.begin());
        
        
        int s = interval.getSeat();
        seats.insert(s);
        
        // build and insert new intervals
        if (interval.l <= s-1)
            intervals.emplace(interval.l, s-1);
        if (s+1 <= interval.r)
            intervals.emplace(s+1, interval.r);
        
        return s;
    }
    
    void leave(int p) {
        int l, r;
        auto it = seats.find(p);
        
        if (it == seats.begin())
            l = 0;
        else
            l = *prev(it) + 1;
        
        if (it == --seats.end())
            r = LEN-1;
        else
            r = *next(it) - 1;
        
        intervals.erase(Interval(l, p-1));
        intervals.erase(Interval(p+1, r));

        intervals.emplace(l, r);
        seats.erase(p);
    }
    
private:
    set<Interval> intervals;
    set<int> seats;
    int LEN;
};

int main(int argc, char** argv)
{
    ExamRoom room(10);
    int seat;
    seat = room.seat();
    cout << "** " << seat << " **" << endl;
    seat = room.seat();
    cout << "** " << seat << " **" << endl;
    seat = room.seat();
    cout << "** " << seat << " **" << endl;
    seat = room.seat();
    cout << "** " << seat << " **" << endl;
    return 0;
}
