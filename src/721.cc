#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
#include "utils.h"

using namespace std;

int getParent(vector<int>& parents, int i) {
    while (parents[i]!=-1) {
        i = parents[i];
    }
    return i;
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
{
    unordered_map<string, int> emails;
    vector<int> parents(accounts.size(), -1);
    unordered_map<int, set<string>> merged;
    vector<vector<string>> res;
    int p1, p2;

    for (int i=0; i<accounts.size(); ++i) {
        for (int j=1; j<accounts[i].size(); ++j) {
            string& e = accounts[i][j];
            auto it = emails.find(e);
            if (it == emails.end()) {
                emails[e] = i;
            } else {
                p1 = getParent(parents, it->second);
                p2 = getParent(parents, i);
                if (p1 != p2) {
                    parents[p1] = p2;
                }
            }
        }
    }

    for (auto& p : emails) {
        p1 = getParent(parents, p.second);
        merged[p1].insert(p.first);
    }

    for (auto& p : merged) {
        res.emplace_back();
        res.back().push_back(accounts[p.first].front());
        res.back().insert(res.back().end(), p.second.begin(), p.second.end());
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<vector<string>> test_case = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};

    auto res = accountsMerge(test_case);
    for (auto& v : res) {
        utils::printContainer(v.begin(), v.end());
    }
    return 0;
}
