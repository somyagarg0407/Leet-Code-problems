#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {

        vector<int> score;
        int sum = 0;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                score.push_back(score[score.size() - 1] + score[score.size() - 2]);//-------------------------
            }
            else if (operations[i] == "C") {
                score.pop_back();//---------------------------------------
            }
            else if (operations[i] == "D") {
                score.push_back(2 * score.back());
            }
            else {
                score.push_back(stoi(operations[i]));//------------------------------------------------------   
            }
        }

        for (int i = 0; i < score.size(); i++) {
            sum += score[i];
        }

        return sum;
    }
};

int main() {
    Solution s;

    vector<string> operations = {"5", "2", "C", "D", "+"};

    cout << s.calPoints(operations);

    return 0;
}
