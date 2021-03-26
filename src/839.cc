#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool isSimilar(const string& s1, const string& s2);
bool connect(unordered_map<int,int>& parents, int n1, int n2);
int root(const unordered_map<int,int>& parents, int node);

int numSimilarGroups(vector<string>& strs) {
    unordered_map<int,int> parents;
    int groups = strs.size();
    
    for (int i=0; i<strs.size(); ++i) {
        for (int j=i+1; j<strs.size(); ++j) {
            if (isSimilar(strs[i], strs[j])) {
                if (connect(parents, i, j)) {
                    --groups;
                }
            }
        }
    }
    
    return groups;
}

bool isSimilar(const string& s1, const string& s2) {
    if (s1.size() != s2.size())
        return true;
    
    int nDiff = 0;
    
    for (int i=0; i<s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            if (nDiff == 2)
                return false;
            ++nDiff;
        }
    }
    
    return true;
}

bool connect(unordered_map<int,int>& parents, int n1, int n2) {
    int r1 = root(parents, n1);
    int r2 = root(parents, n2);
    if (r1 != r2) {
        parents[r2] = r1;
        return true;
    }
    return false;
}

int root(const unordered_map<int,int>& parents, int node) {
    auto it = parents.find(node);
    
    while (it != parents.end()) {
        node = it->second;
        it = parents.find(node);
    }
    
    return node;
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"tars","rats","arts","star"};
    cout << numSimilarGroups(test_case) << endl;

    return 0;
}
