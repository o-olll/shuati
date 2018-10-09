#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int kEmptySlots(vector<int>& flowers, int k)
{
    if (flowers.empty() || flowers.size()-2<k) {
        return -1;
    }

    int blen, bs, n, i, x, b;

    n = flowers.size();
    blen = k + 1;
    bs = (n + blen - 1) / blen;

    printf("n=%d blen=%d bs=%d\n", n, blen, bs);

    vector<int> lower(bs, INT_MAX), upper(bs, INT_MIN);

    for (i=0; i<n; ++i) {
        x = flowers[i] - 1;
        b = x / blen;

        printf("i=%d x=%d b=%d\n", i, x, b);

        // lower bucket
        if (x < lower[b]) {
            lower[b] = x;
            if (b>0 && x-upper[b-1]==k+1)
                return i+1;
        }
        if (x > upper[b]) {
            upper[b] = x;
            if (b<bs-1 && lower[b+1]-x==k+1)
                return i+1;
        }
    }

    return -1;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {5,9,10,6,3,2,8,1,4,7};
    int k = 3;

    if (argc > 1)
        k = atoi(argv[1]);

    cout << kEmptySlots(test_case, k) << endl;

    return 0;
}
