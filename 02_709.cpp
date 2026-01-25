#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] > 64 && s[i] < 91) {   // 'A' to 'Z'
                s[i] = s[i] + 32;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    string s = "HeLLo WoRLd!123";

    cout << sol.toLowerCase(s);

    return 0;
}
