#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    cout << (sol.isPowerOfTwo(n) ? "true" : "false");
    return 0;
}
