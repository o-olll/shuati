#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool hasAllLetters(string& word, vector<int> plate) {
    for (char c : word) {
        if (plate[c-'a'] > 0)
            --plate[c-'a'];
    }
    for (int i : plate) {
        if (i > 0)
            return false;
    }
    return true;
}

string shortestCompletingWordOLD(string licensePlate, vector<string>& words)
{
    vector<int> plate(26, 0);
    int len = INT_MAX, p;

    for (char c : licensePlate) {
        if (islower(c)) {
            ++plate[c-'a'];
        } else if (isupper(c)) {
            ++plate[c-'A'];
        }
    }

    for (int i=0; i<words.size(); ++i) {
        if (hasAllLetters(words[i], plate)) {
            if (words[i].size() < len) {
                len = words[i].size();
                p = i;
            }
        }
    }

    return words[p];
}

vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103};

long product(const string& s)
{
    long res = 1;
    for (char c : s) {
        res *= primes[c-'a'];
    }
    return res;
}

string shortestCompletingWord(string licensePlate, vector<string>& words)
{
    int i, j;
    for (i=0, j=0; i<licensePlate.size(); ++i) {
        if (islower(licensePlate[i]))
            licensePlate[j++] = licensePlate[i];
        if (isupper(licensePlate[i]))
            licensePlate[j++] = licensePlate[i]-'A'+'a';
    }
    licensePlate.resize(j);

    long plateProduct = product(licensePlate);
    int p, len = INT_MAX;

    for (i=0; i<words.size(); ++i) {
        if (product(words[i])%plateProduct == 0) {
            if (words[i].size() < len) {
                len = words[i].size();
                p = i;
            }
        }
    }
    return words[p];
}

int main(int argc, char** argv)
{
    string s = "tR28607";
    vector<string> test_case = {"present","fall","make","change","everything","performance","owner","beat","name","serve"};

    cout << shortestCompletingWord(s, test_case) << endl;
    return 0;
}
