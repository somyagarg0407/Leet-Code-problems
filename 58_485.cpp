#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> freq;
        int count = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1 && i!=nums.size()-1){
                count ++;
            }

            else if(nums[i]==1 && i==nums.size()-1){
                count++;
                freq.push_back(count);
            }

            else{
                freq.push_back(count);
                count=0;
            }
        }

        return *max_element(freq.begin(), freq.end());
    }
};

int main(){

    vector<int> nums = {1,1,0,1,1,1};

    Solution obj;

    int result = obj.findMaxConsecutiveOnes(nums);

    cout<<"Maximum consecutive ones: "<<result;

    return 0;
}