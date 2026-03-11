#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<int> ans;

        for(int i=1;i<nums[0];i++){
            ans.push_back(i);
        }

        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>=2){
                for(int j=1;j<=nums[i]-nums[i-1]-1;j++){
                    ans.push_back(nums[i-1]+j);
                }
            }
        }

        for(int i=nums[nums.size()-1]+1;i<=nums.size();i++){
            ans.push_back(i);
        }

        return ans;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {4,3,2,7,8,2,3,1};

    vector<int> result = obj.findDisappearedNumbers(nums);

    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }

    return 0;
}