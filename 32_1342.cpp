#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;

        while (num > 0) {
            if (num % 2 == 0) {
                num = num / 2;
            } else {
                num = num - 1;
            }
            count++;
        }

        return count;
    }
};

int main() {
    Solution obj;

    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Number of steps: " << obj.numberOfSteps(num) << endl;

    return 0;
}
