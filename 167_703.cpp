#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int k = 3;

    vector<int> nums = {4, 5, 8, 2};

    priority_queue<int, vector<int>, greater<int>> pq;

    // Build Min Heap containing only K largest elements
    for (int i = 0; i < nums.size(); i++) {

        pq.push(nums[i]);

        if (pq.size() > k) {
            pq.pop();
        }
    }

    // Add new value
    int val = 3;

    pq.push(val);

    if (pq.size() > k) {
        pq.pop();
    }

    cout << "Kth largest = " << pq.top() << endl;

    return 0;
}