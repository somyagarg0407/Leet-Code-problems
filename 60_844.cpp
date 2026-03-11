#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {

        vector<char> one;
        vector<char> two;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                one.push_back(s[i]);
            } else if (!one.empty()) {
                one.pop_back();
            }
        }

        for (int i = 0; i < t.length(); i++) {
            if (t[i] != '#') {
                two.push_back(t[i]);
            } else if (!two.empty()) {
                two.pop_back();
            }
        }

        int count = 0;

        if (one.size() == two.size()) {
            for (int i = 0; i < one.size(); i++) {
                if (one[i] == two[i]) {
                    count++;
                }
            }
        } else {
            return false;
        }

        if (count == one.size()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution obj;

    string s, t;
    cin >> s >> t;

    cout << obj.backspaceCompare(s, t);

    return 0;
}