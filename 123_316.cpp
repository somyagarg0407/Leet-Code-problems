#include <bits/stdc++.h>
using namespace std;

string smallestSubsequence(string s)
{
    vector<int> freq(26, 0);
    vector<bool> visited(26, false);
    stack<char> st;

    for (char ch : s)
    {
        freq[ch - 'a']++;
    }

    for (char ch : s)
    {
        freq[ch - 'a']--;

        if (visited[ch - 'a'])
        {
            continue;
        }

        while (!st.empty() && st.top() > ch && freq[st.top() - 'a'] > 0)
        {
            visited[st.top() - 'a'] = false;
            st.pop();
        }

        st.push(ch);
        visited[ch - 'a'] = true;
    }

    string ans;

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << smallestSubsequence(s);

    return 0;
}