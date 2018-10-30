#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "utils.h"

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

ostream& operator<<(ostream& os, Point& p) {
    return os << "(" << p.x << "," << p.y << ")";
}

int cross(Point A, Point B, Point C) {
    long x1 = B.x - A.x;
    long y1 = B.y - A.y;
    long x2 = C.x - B.x;
    long y2 = C.y - B.y;
    return x1 * y2 - y1 * x2;
}

vector<Point> outerTrees(vector<Point>& points)
{
    if (points.size() < 4)
        return points;

    vector<int> fence(2*points.size());
    int i, k, t;

    sort(points.begin(), points.end(), [] (const Point& p1, const Point& p2) {
            return p1.x<p2.x || (p1.x==p2.x && p1.y<p2.y);
        });

    // build lower fence
    for (i=0, k=0; i<points.size(); ++i) {
        while (k>=2 && cross(points[fence[k-2]], points[fence[k-1]], points[i])<0)
            --k;
        fence[k++] = i;
    }

    // build upper fence
    t = k;
    for (i=points.size()-2; i>=0; --i) {
        while (k>t && cross(points[fence[k-2]], points[fence[k-1]], points[i])<0)
            --k;
        fence[k++] = i;
    }

    unordered_set<int> s(fence.begin(), fence.begin()+k);
    vector<Point> res(s.size());

    i = 0;
    for (auto it=s.begin(); it!=s.end(); ++it)
        res[i++] = points[*it];

    return res;
}

int main(int argc, char** argv)
{
    vector<Point> test_case = {{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}}, res;

    res = outerTrees(test_case);

    utils::printContainer(res.begin(), res.end());

    return 0;
}
