#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<int> space;

        int count = 0;
        int j = s.length() - 1;

       
        while (j >= 0 && s[j] == ' ') {
            count++;
            j--;
        }

        
        for (int i = 0; i < s.length() - count; i++) {
            if (s[i] == ' ') {
                space.push_back(i);
            }
        }

        
        if (space.empty()) {
            return s.length() - count;
        }

        int diff = s.length() - count - space.back() - 1;
        return diff;
    }
};

int main() {
    Solution sol;

    string s;
    getline(cin, s); 

    cout << sol.lengthOfLastWord(s);

    return 0;
}
