#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

string toWords(int num)
{
    vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                         "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string s100, s10, s1;

    s100 = num/100==0 ? "" : v1[num/100] + " hundred";
    s10 = v2[(num%100)/10];
    s1 = num%100>19 ? v1[num%10] : v1[num%100];

    return s100+(s100.empty()?"":" ")+s10+(s10.empty()?"":" ")+s1;
}

string numberToWords(int num)
{
    vector<string> unit{"billion", "million", "thousand", ""};
    int n;
    string res;

    for (int k=1e9,i=0; i<4; k/=1000,++i) {
        n = num / k;
        if (n != 0) {
            res += toWords(n) + " " + unit[i] + " ";
            num %= k;
        }
    }

    while (res.back() == ' ')
        res.pop_back();

    return res;
}

int main(int argc, char** argv)
{
    cout << numberToWords(atoi(argv[1]));
    return 0;
}
