#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool rowHasPixel(vector<string>& image, int row)
{
    for (char c : image[row])
        if (c == '1')
            return true;
    return false;
}

bool colHasPixel(vector<string>& image, int col)
{
    for (int i=0; i<image.size(); ++i) {
        if (image[i][col] == '1')
            return true;
    }
    return false;
}

int findUpperBound(vector<string>& image, int x)
{
    int l=0, r=x, m;

    while (l < r) {
        m = (l + r) / 2;
        if (rowHasPixel(image, m))
            r = m;
        else
            l = m + 1;
    }

    return l;
}

int findLeftBound(vector<string>& image, int x)
{
    int l=0, r=x, m;

    while (l < r) {
        m = (l + r) / 2;
        if (colHasPixel(image, m))
            r = m;
        else
            l = m + 1;
    }

    return l;
}

int findLowerBound(vector<string>& image, int x)
{
    int l=x, r=image.size(), m;

    while (l < r) {
        m = (l + r) / 2;
        if (rowHasPixel(image, m))
            l = m + 1;
        else
            r = m;
    }

    return l;
}

int findRightBound(vector<string>& image, int x)
{
    int l=x, r=image[0].size(), m;

    while (l < r) {
        m = (l + r) / 2;
        if (colHasPixel(image, m))
            l = m + 1;
        else
            r = m;
    }

    return l;
}

int minArea(vector<string>& image, int x, int y)
{
    int upper, lower, left, right;

    upper = findUpperBound(image, x);
    lower = findLowerBound(image, x);
    left = findLeftBound(image, y);
    right = findRightBound(image, y);

    printf("u=%d d=%d l=%d r=%d\n", upper, lower, left, right);

    return (lower - upper) * (right - left);
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"0000",
                                "1110",
                                "0110",
                                "0100"};

    cout << minArea(test_case, atoi(argv[1]), atoi(argv[2])) << endl;;

    return 0;
}
