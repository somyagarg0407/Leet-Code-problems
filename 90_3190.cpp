#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 3 != 0) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Minimum operations: " << obj.minimumOperations(nums);

    return 0;
}