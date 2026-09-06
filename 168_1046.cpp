#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        int x = 0;
        int y = 0;

        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        while (pq.size() > 1) {
            y = pq.top();
            pq.pop();

            x = pq.top();
            pq.pop();

            if (x < y) {
                pq.push(y - x);
            }
            else if (x == y) {
                continue;
            }
        }

        if (pq.size() == 1) {
            return pq.top();
        }

        return 0;
    }
};

int main() {
    Solution s;

    vector<int> stones = {2, 7, 4, 1, 8, 1};

    cout << s.lastStoneWeight(stones) << endl;

    return 0;
}