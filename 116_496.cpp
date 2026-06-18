#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {

        vector<int> ans;

        for (int i = 0; i < num1.size(); i++) {

            int index = -1;

            //------ Find position of num1[i] in num2
            for (int j = 0; j < num2.size(); j++) {
                if (num1[i] == num2[j]) {
                    index = j;
                    break;
                }
            }

            bool found = false;

            //---------- Search for next greater element on the right
            for (int j = index + 1; j < num2.size(); j++) {
                if (num2[j] > num2[index]) {
                    ans.push_back(num2[j]);
                    found = true;
                    break;
                }
            }

            // -----If no greater element found
            if (!found) {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

int main() {

    vector<int> num1 = {4, 1, 2};
    vector<int> num2 = {1, 3, 4, 2};

    Solution obj;

    vector<int> result = obj.nextGreaterElement(num1, num2);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}