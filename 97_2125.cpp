#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> ans;
        int count = 0;

        for (int i = 0; i < bank.size(); i++) {
            for (int j = 0; j < bank[0].size(); j++) {
                if (bank[i][j] == '1') {
                    count++;
                }
            }

            if (count != 0) {
                ans.push_back(count);
            }

            count = 0;
        }

        int final = 0;

        for (int i = 1; i < ans.size(); i++) {
            final += ans[i] * ans[i - 1];
        }

        return final;
    }
};

int main() {
    Solution obj;

    vector<string> bank = {"011001", "000000", "010100", "001000"};

    cout << obj.numberOfBeams(bank);

    return 0;
}