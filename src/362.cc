#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "utils.h"

using namespace std;

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() : _total(0) {}

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (_q.empty() || _q.back().first != timestamp)
            _q.emplace(timestamp, 1);
        else
            ++_q.back().second;
        ++_total;
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!_q.empty() && timestamp - _q.front().first >= 300) {
            _total -= _q.front().second;
            _q.pop();
        }
        cout << "size = " << _q.size() << endl;
        return _total;
    }

private:
    queue<pair<int,int>> _q;
    long long _total;
};

class HitCounterTest {
public:
    /** Initialize your data structure here. */
    HitCounterTest() {}

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front() >= 300) {
            q.pop();
        }
        cout << "size = " << q.size() << endl;
        return q.size();
    }

private:
    queue<int> q;
};

int main(int argc, char** argv)
{
    vector<int> test_case = {7,7,14,14,28,42,49,56,63,77,77,84,91,98,126,126,140,147,147,168,168,175,182,189,189,196,196,203,210,224,238,238,245,245,252,259,266,273,273,287,294,301,308,315,315,329,329,336,343,350,357,357,364,364,371,371,385,385,392,399,420,420,427,434,434,441,441,455,462,462,469,497,504,511,518,532,553,567,574,574,581,581,588,588,595,595,609,616,616,623,637,637,658,665,665,672,679,686,693,714,721,728,728,735,742,742,749,770,777,777,791,791,805,819,826,826,840,861,868,875,875,889,889,896,910,910,917,917,924,931,938,945,952,966,980,987,994,1008,1015,1036,1036,1050,1057,1057,1064,1071,1071,1078,1085,1085,1092,1092,1113,1120,1120,1127,1141,1148,1155,1155,1162,1169,1176,1176,1183,1190,1190,1197,1197,1204,1211,1218,1225,1232,1232,1239,1253,1260,1260,1274,1302,1309,1309,1316,1316,1330,1330,1337,1337,1344,1351,1358,1358,1365,1372,1379,1386,1386,1393,1400};
    vector<int> gettings = {16,19,33,45,57,62,68,75,80,106,119,124,130,133,137,170,176,186,187,196};
    HitCounter hc1;
    HitCounterTest hc2;

    int c1, c2, i, j;

    for (i=0,j=0; i<test_case.size(); ++i) {
        hc1.hit(test_case[i]);
        hc2.hit(test_case[i]);
        if (i == gettings[j]) {
            c1 = hc1.getHits(test_case[i]);
            c2 = hc2.getHits(test_case[i]);
            if (c1 != c2) {
                cout << "ERROR:" << endl;
            }
            printf("%d: %d %d\n", test_case[i], c1, c2);
            ++j;
        }
    }

    return 0;
}
