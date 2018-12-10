#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

void heapPermutation(string& s, int size)
{
    if (size == 1)
    {
        cout << s << endl;
        return;
    }

    for (int i=0; i<size-1; i++)
    {
        //printf("%d %d %s\n", size, i, s.c_str());
        heapPermutation(s, size-1);

        // if size is odd, swap first and last
        // element
        if (size%2 == 1)
            swap(s[0], s[size-1]);

        // If size is even, swap ith and last
        // element
        else
            swap(s[i], s[size-1]);
    }
    heapPermutation(s, size-1);
}

int main(int argc, char** argv)
{
    string s(argv[1]);
    heapPermutation(s, s.size());

    return 0;
}
