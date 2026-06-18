// Idea:
// 1. Path ko '/' ke basis par parse karo.
// 2. "."  -> Ignore
// 3. ".." -> Stack se pop (agar empty na ho)
// 4. Normal folder -> Stack me push
// 5. End me stack ko reverse order me answer me convert karo.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        string curr = "";

        for (int i = 0; i <= path.size(); i++) {

            // Last character ke baad bhi process karna hai
            if (i == path.size() || path[i] == '/') {

                if (curr == "" || curr == ".") {
                    // Ignore
                }

                else if (curr == "..") {

                    if (!st.empty()) {
                        st.pop();
                    }

                }

                else {
                    st.push(curr);
                }

                curr = "";
            }

            else {
                curr += path[i];
            }
        }

        vector<string> temp;

        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        string ans = "";

        for (string folder : temp) {
            ans += "/";
            ans += folder;
        }

        if (ans == "") {
            return "/";
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string path = "/.../a/../b/c/../d/./";

    cout << "Original Path : " << path << endl;
    cout << "Simplified Path : " << obj.simplifyPath(path) << endl;

    return 0;
}