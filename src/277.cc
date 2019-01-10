#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<vector<bool>> relation;

bool knows(int a, int b)
{
    return relation[a][b];
}

int findCelebrity(int n)
{
    int celebrity = 0;

    for (int i=0; i<n; ++i) {
        if (knows(celebrity, i))
            celebrity = i;
    }

    for (int i=0; i<celebrity; ++i) {
        if (knows(celebrity, i) || !knows(i, celebrity)) {
            return -1;
        }
    }

    for (int i=celebrity+1; i<n; ++i) {
        if (!knows(i, celebrity))
            return -1;
    }

    return celebrity;
}

int main(int argc, char** argv)
{
    relation = {{false, false, true, true, false, false},
                {false, false, true, true, false, false},
                {false, false, false, true, false, false},
                {false, false, false, false, false, false},
                {true, false, true, true, false, false},
                {false, false, true, true, false}};

    cout << findCelebrity(6);

    return 0;
}
