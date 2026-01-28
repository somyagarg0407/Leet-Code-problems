#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {

        string updated;

        for (int i = 0; i < address.length(); i++) {
            if (address[i] == '.') {
                updated += "[.]";
            } else {
                updated += address[i];
            }
        }

        return updated;
    }
};

int main() {
    Solution sol;

    string address = "1.1.1.1";
    cout << sol.defangIPaddr(address);

    return 0;
}
