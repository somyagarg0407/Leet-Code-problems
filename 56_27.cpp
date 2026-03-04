#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                count ++;
                nums[k]=nums[i];
                k++;
            }
        }
        return count;
    }
};

int main(){
    vector<int> nums = {3,2,2,3};
    int val = 3;

    Solution obj;
    int result = obj.removeElement(nums,val);

    cout<<"k = "<<result<<endl;

    cout<<"Array after removal: ";
    for(int i=0;i<result;i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}