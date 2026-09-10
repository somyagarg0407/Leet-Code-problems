#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, k;

    cout << "Enter number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    cout << "Enter the points:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    cout << "Enter k: ";
    cin >> k;

    vector<vector<int>> ans;

    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < points.size(); i++)
    {
        int distance = points[i][0] * points[i][0] +
                       points[i][1] * points[i][1];

        pq.push({distance, i});

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        int index = pq.top().second; //     -------IMPORTANT-------
        ans.push_back(points[index]);
        pq.pop();
    }

    cout << "\nK closest points:\n";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "] ";
    }

    cout << endl;

    return 0;
}