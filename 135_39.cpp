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

    if (index == candidates.size())
    {
        return;
    }

    if (candidates[index] <= remTarget)
    {
        curr.push_back(candidates[index]);

        solve(index, remTarget - candidates[index], candidates);

        curr.pop_back();
    }

    solve(index + 1, remTarget, candidates);
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    solve(0, target, candidates);

    for (auto &v : ans)
    {
        cout << "[ ";

        for (auto &x : v)
            cout << x << " ";

        cout << "]\n";
    }

    return 0;
}