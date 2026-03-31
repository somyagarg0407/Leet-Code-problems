#include <iostream>
using namespace std;

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        return false;
    }
};

int main() {
    Solution obj;
    int n;

    cout << "Enter n: ";
    cin >> n;

    if (obj.isStrictlyPalindromic(n)) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}