#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int magicalString(int n) {
    string s = "122";
    int j = 2;

    while (s.size() < n) {
        s.append(s[j++]-'0', '3'-s.back()+'0');
    }

    return count(s.begin(), s.begin()+n, '1');
}

int main(int argc, char** argv)
{
    cout <<magicalString(atoi(argv[1])) << endl;
    return 0;
}
