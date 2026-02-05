#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> digits;

        while (n > 0) {
            int rem = n % 10;
            digits.push_back(rem);
            n = n / 10;
        }

        int sum = 0;
        int product = 1;

        for (int i = 0; i < digits.size(); i++) {
            sum += digits[i];
            product *= digits[i];
        }

        return product - sum;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Product - Sum = " << obj.subtractProductAndSum(n) << endl;

    return 0;
}
