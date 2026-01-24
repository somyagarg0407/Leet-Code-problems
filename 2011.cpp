#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int sum = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "++X")
                sum += 1;
            if (operations[i] == "X++")
                sum += 1;
            if (operations[i] == "--X")
                sum -= 1;
            if (operations[i] == "X--")
                sum -= 1;
        }
        return sum;
    }
};

int main() {
    Solution s;

    vector<string> operations = {"--X", "X++", "X++"};

    cout << s.finalValueAfterOperations(operations);

    return 0;
}
