#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;

        // Count frequency of each task
        for (char task : tasks) {
            freq[task]++;
        }

        // Max heap
        priority_queue<int> pq;

        for (auto it : freq) {
            pq.push(it.second);
        }

        int count = 0;

        while (!pq.empty()) {

            vector<int> temp;
            int tasksDone = 0;

            // One cycle has n + 1 positions
            for (int i = 0; i <= n; i++) {

                if (!pq.empty()) {

                    int f = pq.top();
                    pq.pop();

                    f--;

                    if (f > 0) {
                        temp.push_back(f);
                    }

                    tasksDone++;
                    count++;
                }
                else {
                    break;
                }
            }

            // Put remaining frequencies back into heap
            for (int f : temp) {
                pq.push(f);
            }

            // Fill empty positions with idle time
            // only if tasks are still remaining
            if (!pq.empty()) {
                count += (n + 1) - tasksDone;
            }
        }

        return count;
    }
};

int main() {

    Solution solution;

    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    int result = solution.leastInterval(tasks, n);

    cout << "Minimum CPU intervals: " << result << endl;

    return 0;
}

