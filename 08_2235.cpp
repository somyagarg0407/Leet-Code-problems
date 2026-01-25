#include <iostream>
using namespace std;

class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};

int main() {
    Solution s;
    int a, b;

    cin >> a >> b;          // input two numbers
    cout << s.sum(a, b);    // output their sum

    return 0;
}
    