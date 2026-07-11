#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> curr;

void solve(int index, int remTarget, vector<int>& candidates)
{
    if (remTarget == 0)
    {
        ans.push_back(curr);
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }

        if (candidates[i] > remTarget)
        {
            break;
        }

        curr.push_back(candidates[i]);

        solve(i + 1, remTarget - candidates[i], candidates);

        curr.pop_back();
    }
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    sort(candidates.begin(), candidates.end());

    solve(0, target, candidates);

    for (auto &v : ans)
    {
        cout << "[ ";

        for (auto &x : v)
        {
            cout << x << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}