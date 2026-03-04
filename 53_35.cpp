#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(nums[mid] < target)
                low = mid + 1;
            
            else
                high = mid - 1;
        }
        
        return low;   // insert position
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    int result = obj.searchInsert(nums, target);

    cout << "Position: " << result << endl;

    return 0;
}