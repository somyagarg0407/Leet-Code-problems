#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<int> start;
        vector<int> end;

        if(nums.size() == 0) return {}; //--------------IMP---------------

        else start.push_back(nums[0]);

        for (int i = 1; i < nums.size() ; i++) {
            if (nums[i] != 1 + nums[i - 1]) {
                start.push_back(nums[i]);
                end.push_back(nums[i - 1]);
            }
        }

        end.push_back(nums[nums.size() - 1]);

        vector<string> ans;

        for (int i = 0; i < start.size(); i++) {
            if (start[i] == end[i]) {
                ans.push_back(to_string(start[i]));
            }

            else {
                ans.push_back(to_string(start[i]) + "->" + to_string(end[i]));
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {0,1,2,4,5,7};

    vector<string> result = obj.summaryRanges(nums);

    for(string s : result){
        cout << s << " ";
    }

    return 0;
}