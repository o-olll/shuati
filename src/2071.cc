#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
#include "utils.h"

using namespace std;

bool canAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength);

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
	sort(tasks.begin(), tasks.end());
	sort(workers.begin(), workers.end());
	utils::printContainer(tasks.begin(), tasks.end());

	int l = 0, r = min(tasks.size(), workers.size());
	while (l < r) {
		int m = l + (r - l) / 2;
		printf("---\nl=%d, r=%d, m=%d\n", l, r, m);
		vector<int> tempTasks(tasks.begin(), tasks.begin()+m+1);
		vector<int> tempWorkers(workers.rbegin(), workers.rbegin()+m+1);
		if (canAssign(tempTasks, tempWorkers, pills, strength)) {
			cout << "yes" << endl;
			l = m + 1;
		} else {
			cout << "no" << endl;
			r = m;
		}
	}

	return l;
}

bool canAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
	multiset<int> workerSet(workers.begin(), workers.end());
	utils::printContainer(workerSet.begin(), workerSet.end());
	int nTasks = 0;

	for (auto it=tasks.rbegin(); it!=tasks.rend(); it++) {
		int t = *it;
		cout << "t=" << t << endl;
		auto wIt = workerSet.lower_bound(t);
		if (wIt != workerSet.end()) {
		    cout << "lb 1: " << *wIt << endl;
			++nTasks;
			workerSet.erase(wIt);
			cout << "worker: ";
			utils::printContainer(workerSet.begin(), workerSet.end());
		} else if (pills > 0) {
			auto wIt = workerSet.lower_bound(t-strength);
			if (wIt != workerSet.end()) {
				cout << "lb 2: " << *wIt << endl;
				++nTasks;
				pills--;
				workerSet.erase(wIt);
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

	return true;
}

int main(int argc, char** argv)
{
    vector<int> tasks= {74,41,64,20,28,52,30,4,4,63}, workers = {38};
	cout << maxTaskAssign(tasks, workers, 0, 5) << endl;

    return 0;
}
