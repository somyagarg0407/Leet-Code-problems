#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    unordered_map<int, int> freq;
    vector<int> ans;

    for (int num : nums)
    {
        freq[num]++;
    }

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    for (auto it : freq)
    {
        pq.push({it.second, it.first});
    }

    while (pq.size() > k)
    {
        pq.pop();
    }

    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    cout << "Top " << k << " frequent elements: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}