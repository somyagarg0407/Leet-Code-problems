#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> ans;
    string curr;
    vector<string> keypad = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(int index, string nums) {

        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = keypad[nums[index] - '0'];

        for (int i = 0; i < letters.size(); i++) {

            curr.push_back(letters[i]);
            solve(index + 1, nums);
            curr.pop_back();

        }
    }

    vector<string> letterCombinations(string nums) {

        // Edge case for empty input
        if (nums.empty())
            return {};

        solve(0, nums);
        return ans;
    }
};

int main() {

    Solution obj;

    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    vector<string> result = obj.letterCombinations(digits);

    cout << "Letter Combinations:\n";

    for (string s : result) {
        cout << s << " ";
    }

    cout << endl;

    return 0;
}