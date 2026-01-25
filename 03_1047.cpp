#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string updated;

        if (s.empty()) {
            return s;
        }

        updated.push_back(s[0]);

        for (int i = 1; i < s.length(); i++) {

            if (updated.empty()) {
                updated.push_back(s[i]);
            }
            else if (s[i] == updated.back()) {
                updated.pop_back();
            }
            else {
                updated.push_back(s[i]);
            }
        }

        return updated;
    }
};

int main() {
    Solution sol;

    string s = "abbaca";   // sample input

    cout << sol.removeDuplicates(s);

    return 0;
}
