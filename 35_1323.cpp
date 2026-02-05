#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        int sum = 0;
        vector<int> digits;

        while (num > 0) {
            int rem = num % 10;
            digits.push_back(rem);
            num /= 10;
        }

        // change first 6 from left to 9
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 6) {
                digits[i] = 9;
                break;
            }
        }

        int place = 1;
        for (int j = 0; j < digits.size(); j++) {
            sum += digits[j] * place;
            place *= 10;
        }

        return sum;
    }
};

int main() {
    Solution obj;

    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Maximum 69 Number: " << obj.maximum69Number(num) << endl;

    return 0;
}
