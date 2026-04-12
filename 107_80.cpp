#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;

        for (int x : nums) {
            if (i < 2 || x != nums[i - 2]) {
                nums[i] = x;
                i++;
            }
        }

        return i;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    Solution obj;
    int k = obj.removeDuplicates(nums);

    cout << "Length after removing duplicates: " << k << endl;

    cout << "Array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}