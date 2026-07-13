#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> ans;
vector<string> curr;

bool isPalindrome(string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

void solve(int index, string &s) {

    if (index == s.size()) {
        ans.push_back(curr);
        return;
    }

    for (int i = index; i < s.size(); i++) {

        if (isPalindrome(s, index, i)) {

            string part = s.substr(index, i - index + 1);

            curr.push_back(part);
            solve(i + 1, s);
            curr.pop_back();
        }
    }
}

int main() {

    string s;
    cin >> s;

    solve(0, s);

    for (auto &partition : ans) {
        cout << "[ ";
        for (auto &str : partition) {
            cout << "\"" << str << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}