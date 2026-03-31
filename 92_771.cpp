#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;

        for (int i = 0; i < jewels.size(); i++) {
            for (int j = 0; j < stones.size(); j++) {
                if (jewels[i] == stones[j]) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution obj;
    string jewels, stones;

    cout << "Enter jewels: ";
    cin >> jewels;

    cout << "Enter stones: ";
    cin >> stones;

    cout << "Number of jewels in stones: "
         << obj.numJewelsInStones(jewels, stones);

    return 0;
}