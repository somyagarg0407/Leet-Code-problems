#include <iostream>
using namespace std;

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + (t * 2);
    }
};

int main() {
    Solution obj;
    int num, t;

    cout << "Enter num and t: ";
    cin >> num >> t;

    cout << "Result: " << obj.theMaximumAchievableX(num, t);

    return 0;
}