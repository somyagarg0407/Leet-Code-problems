#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
        }

        int windowSize = s1.length();

        for (int i = 0; i < s2.length(); i++) {

            freq2[s2[i] - 'a']++;

            if (i >= windowSize) {
                freq2[s2[i - windowSize] - 'a']--;
            }

            if (freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    string s1 = "ab";
    string s2 = "eidbaooo";

    if (obj.checkInclusion(s1, s2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}