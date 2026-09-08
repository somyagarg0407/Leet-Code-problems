#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countRotations(string s, int k) {
    int ans = 0;
    vector<int> score;
    int count = 0;

    for (int r = 0; r < s.size(); r++) {
        count = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                count++;
            }
        }

        score.push_back(count);

        // Rotate string left by 1 position
        char temp = s[0];

        for (int i = 0; i < s.size() - 1; i++) {
            s[i] = s[i + 1];
        }

        s[s.size() - 1] = temp;
    }

    for (int i = 0; i < score.size(); i++) {
        if (score[i] == k) {
            ans++;
        }
    }

    return ans;
}

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    int result = countRotations(s, k);

    cout << "Number of rotations: " << result << endl;

    return 0;
}