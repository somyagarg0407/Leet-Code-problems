#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int top = -1;

        for (int i = 0; i < s.size(); i++) {
            if (!st.empty()) {
                if (st.top() - s[i] == 32 || st.top() - s[i] == -32) {
                    st.pop();
                    top--;
                }
                else {
                    st.push(s[i]);
                    top++;
                }
            }
            else {
                st.push(s[i]);
                top++;
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    cout << obj.makeGood(s);

    return 0;
}