#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int leastInterval(vector<char>& tasks, int n)
{
    vector<int> count(128, 0);
    int mxTask=0, nMxTask=0, fill, leftTasks;

    for (char task : tasks) {
        ++count[task];
        if (mxTask < count[task]) {
            mxTask = count[task];
            nMxTask = 1;
        } else if (mxTask == count[task]) {
            ++nMxTask;
        }
    }

    fill = (mxTask - 1) * (n - nMxTask + 1);
    leftTasks = tasks.size() - mxTask*nMxTask;
    //    printf("size=%d fill=%d leftTasks=%d\n", tasks.size(), fill, leftTasks);
    return tasks.size() + (fill>leftTasks ? (fill-leftTasks) : 0);
}

int main(int argc, char** argv)
{
    vector<char> test_case = {'A','A','A','A','A',
                              'B','B','B','B','B',
                              'C','C','C',
                              'D','D','D','D'};

    cout << leastInterval(test_case, 4);

    return 0;
}
