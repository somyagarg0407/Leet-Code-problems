#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        vector<char> number; // (unused, but kept as in your code)
        int count = 0;

        int i = digits.size() - 1;

        while (i >= 0 && digits[i] == 9) {
            count++;
            i--;
        }

        if (count > 0 && count != digits.size()) {
            for (int j = digits.size() - 1; j > digits.size() - count - 1; j--) {
                digits[j] = 0;
            }
            digits[digits.size() - count - 1] += 1;
        }
        else {
            digits[digits.size() - 1] = 1 + digits[digits.size() - 1];
        }

        if (count == digits.size()) {
            digits[0] = 1;
            for (int k = 1; k < digits.size(); k++) {
                digits[k] = 0;
            }
            digits.push_back(0);
        }

        return digits;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;   // number of digits

    vector<int> digits(n);
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    vector<int> result = sol.plusOne(digits);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
