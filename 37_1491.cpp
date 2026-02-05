#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        double mx = *max_element(salary.begin(), salary.end());
        double mn = *min_element(salary.begin(), salary.end());
        double ans = (accumulate(salary.begin(), salary.end(), 0.0) - mx - mn)
                     / (salary.size() - 2);
        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of salaries: ";
    cin >> n;

    vector<int> salary(n);
    cout << "Enter salaries: ";
    for (int i = 0; i < n; i++) {
        cin >> salary[i];
    }

    cout << "Average salary (excluding min & max): "
         << obj.average(salary) << endl;

    return 0;
}
