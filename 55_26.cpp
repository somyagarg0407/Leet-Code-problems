#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int slow = 0;
        int fast = 1;

        if(nums.size() == 0) 
            return 0;

        while(fast < nums.size()){
            if(nums[slow] == nums[fast]){
                fast++;
            }
            else{
                slow++;
                nums[slow] = nums[fast];
                fast++;
            }
        }

        return slow + 1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int k = obj.removeDuplicates(nums);

    cout << "k = " << k << endl;
    cout << "Modified array (first k elements): ";

    for(int i = 0; i < k; i++)
        cout << nums[i] << " ";

    return 0;
}