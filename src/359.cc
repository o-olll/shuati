#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

class Logger {
public:
    Logger() {}

    bool shouldPrintMessage(int timestamp, string message) {
        auto it = _logs.find(message);
        if (it==_logs.end() || timestamp-it->second>10) {
            _logs[message] = timestamp;
            return true;
        }
        return false;
    }

private:
    unordered_map<string, int> _logs;
};

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    return 0;
}
