#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int teams = n;
        int matches = 0;

        while (teams > 1) {
            if (teams % 2 == 0) {
                matches += teams / 2;
                teams = teams / 2;
            } else {
                matches += (teams - 1) / 2;
                teams = (teams + 1) / 2;
            }
        }

        return matches;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of teams: ";
    cin >> n;

    cout << "Total matches: " << obj.numberOfMatches(n) << endl;

    return 0;
}
