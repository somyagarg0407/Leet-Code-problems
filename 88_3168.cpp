#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int maxChairs = 0;
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'E') {
                sum += 1;
            } else {
                sum -= 1;
            }

            if (sum > maxChairs) {
                maxChairs = sum;
            }
        }
        return maxChairs;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Minimum chairs needed: " << obj.minimumChairs(s);

    return 0;
}