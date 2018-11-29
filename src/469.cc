#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int product(int x1, int y1, int x2, int y2)
{
    return x1*y2 - x2*y1;
}

bool isConvex(vector<vector<int>>& points)
{
    if (points.size() < 4)
        return true;

    int p = product(points[1][0]-points[0][0],
                    points[1][1]-points[0][1],
                    points[2][0]-points[1][0],
                    points[2][1]-points[2][1]),
        n = points.size();

    for (int i=3, current; i<n+2; ++i) {
        current = product(points[(i-1)%n][0]-points[(i-2)%n][0],
                          points[(i-1)%n][1]-points[(i-2)%n][1],
                          points[i%n][0]-points[(i-1)%n][0],
                          points[i%n][1]-points[(i-1)%n][1]);

        if ((p>0&&current<0) || (p<0&&current>0))
            return false;
    }

    return true;
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{0,0},{0,10},{10,10},{10,0},{-5,-5}};

    cout << boolalpha << isConvex(test_case) << endl;

    return 0;
}
