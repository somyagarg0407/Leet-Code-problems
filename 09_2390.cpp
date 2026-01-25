#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) {

        string updated;

        if (s.empty()) {//-----------------------------------
            return s;
        }

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {
                updated.pop_back();
            } else {
                updated.push_back(s[i]);
            }
        }

        return updated;
    }
};

int main() {
    Solution sol;

    string s = "leet**cod*e";   // sample input

    cout << sol.removeStars(s);

    return 0;
}
