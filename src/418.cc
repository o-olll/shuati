#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int wordsTyping(vector<string>& sentence, int rows, int cols)
{
    int r, current, i, n;
    string s;

    for (auto& word : sentence) {
        s.append(word);
        s.push_back(' ');
    }
    n = s.size();

    for (r=0, current=0, i=0; r<rows; ++r) {
        i += cols;
        while (i>=0 && s[i%n]!=' ') {
            --i;
        }
        ++i;
    }

    return i / n;
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"a"};

    cout << wordsTyping(test_case, atoi(argv[1]), atoi(argv[2])) << endl;

    return 0;
}
