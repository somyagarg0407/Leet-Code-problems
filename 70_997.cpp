#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> score(n + 1, 0);

        for (int i = 0; i < trust.size(); i++) {
            int a = trust[i][0];
            int b = trust[i][1];

            score[a]--;
            score[b]++;
        }

        for (int i = 1; i <= n; i++) {
            if (score[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    int n = 3;
    vector<vector<int>> trust = {{1,3},{2,3}};

    cout << obj.findJudge(n, trust);

    return 0;
}