#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> temp;
        vector<int> temp2;

        if (x < 0) {
            return false;
        }

        while (x > 0) {
            temp.push_back(x % 10);
            x = x / 10;
        }

        for (int i = temp.size() - 1; i >= 0; i--) {
            temp2.push_back(temp[i]);
        }

        return temp == temp2;
    }
};

int main() {
    Solution sol;

    int x;
    cin >> x;   // input number

    if (sol.isPalindrome(x)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
