#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;

        for (int i = 1; i < s.length(); i++) {
            sum += abs(s[i] - s[i - 1]);
        }

        return sum;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Score: " << obj.scoreOfString(s);

    return 0;
}