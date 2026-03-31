#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if (abs(z - x) < abs(z - y)) return 1;
        if (abs(z - y) < abs(z - x)) return 2;
        return 0;
    }
};

int main() {
    Solution obj;
    int x, y, z;

    cout << "Enter x, y, z: ";
    cin >> x >> y >> z;

    cout << "Result: " << obj.findClosest(x, y, z);

    return 0;
}