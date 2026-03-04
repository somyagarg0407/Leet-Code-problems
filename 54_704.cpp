#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int final = 0;
        
        while(low <= high){
            int mid = (low + high) / 2;

            if(target > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }

            if(nums[mid] == target){
                final = mid;
                break;
            }
            else{
                final = -1;
            }
        }

        return final;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int result = obj.search(nums, target);

    cout << "Index: " << result << endl;

    return 0;
}