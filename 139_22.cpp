#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;
    string curr;

    void solve(int open, int close, int n) {

        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            solve(open + 1, close, n);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            solve(open, close + 1, n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        solve(0, 0, n);
        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<string> result = obj.generateParenthesis(n);

    cout << "\nGenerated Parentheses:\n";
    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}