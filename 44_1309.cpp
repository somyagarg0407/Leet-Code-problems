#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        vector<char> input;
        vector<char> final;

        for (int i = 0; i < s.length(); i++) {
            input.push_back(s[i]);
        }

        for (int i = input.size() - 1; i >= 0; i--) {
            if (input[i] == '#') {
                final.push_back((10 * input[i - 2]) + input[i - 1] + 80);
                i = i - 2;
            }
            else {
                final.push_back(48 + input[i]);
            }
        }

        string output;

        for (int i = final.size() - 1; i >= 0; i--) {
            output += final[i];
        }

        return output;
    }
};

int main() {
    Solution obj;
    string s = "10#11#12";
    cout << obj.freqAlphabets(s);
    return 0;
}