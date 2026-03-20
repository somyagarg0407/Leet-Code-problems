#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.size() == 0) return 0;
        if (needle.size() > haystack.size()) return -1;

        int count = 0;

        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            if (needle[0] == haystack[i]) {
                for (int j = 0; j < needle.size(); j++) {
                    if (needle[j] == haystack[i + j]) {
                        count++;
                    } else {
                        break;
                    }
                }
            }

            if (count == needle.size()) {
                return i;
            }

            count = 0;
        }

        return -1;
    }
};

int main() {
    Solution obj;

    string haystack, needle;
    cin >> haystack;
    cin >> needle;

    cout << obj.strStr(haystack, needle);

    return 0;
}