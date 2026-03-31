#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int odd = 0;
        int even = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                even += nums[i];
            } else {
                odd += nums[i];
            }
        }

        return even - odd;
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

    cout << "Alternating Sum: " << obj.alternatingSum(nums);

    return 0;
}