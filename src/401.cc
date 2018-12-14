#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<string> readBinaryWatch(int num)
{
    vector<vector<string>> hour =
                      {{"0"},
                       {"1", "2", "4", "8"},
                       {"3", "5", "6", "9", "10"},
                       {"7", "11"}};
    vector<vector<string>> minute =
                        {{"00"},
                         {"01", "02", "04", "08", "16", "32"},
                         {"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"},
                         {"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56"},
                         {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"},
                         {"31", "47", "55", "59"}};
    vector<string> res;
    for (int i=0,j; i<=3 && i<=num; ++i) {
        j = num - i;
        if (j > 5)
            continue;
        for (string h : hour[i]) {
            for (string m : minute[j]) {
                res.push_back(h+":"+m);
            }
        }
    }
    return res;
}

int main(int argc, char** argv)
{
    auto v = readBinaryWatch(atoi(argv[1]));
    utils::printContainer(v.begin(), v.end());
    return 0;
}
