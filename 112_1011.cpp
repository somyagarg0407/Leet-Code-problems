#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int left = 0;
        int right = 0;

        for (int i = 0; i < weights.size(); i++) {
            left = max(left, weights[i]);
            right += weights[i];
        }

        while (left < right) {

            int mid = left + (right - left) / 2;

            int currentSum = 0;
            int requiredDays = 1;

            for (int i = 0; i < weights.size(); i++) {

                if (currentSum + weights[i] > mid) {
                    requiredDays++;
                    currentSum = weights[i];
                } 
                else {
                    currentSum += weights[i];
                }
            }

            if (requiredDays <= days) {
                right = mid;
            } 
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main() {
    int n, days;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cin >> days;

    Solution obj;
    cout << obj.shipWithinDays(weights, days);

    return 0;
}