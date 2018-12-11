#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

string reverseStr(string s, int k)
{
    string::iterator it;

    for (it=s.begin(); it+k<=s.end(); it+=2*k) {
        reverse(it, it+k);
    }

    reverse(it, s.end());

    return s;
}

int main(int argc, char** argv)
{
    cout << argv[1] << " " << atoi(argv[2]) << endl;
    cout << reverseStr(argv[1], atoi(argv[2]));

    return 0;
}
