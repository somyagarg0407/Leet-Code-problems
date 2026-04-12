#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1,right=*max_element(piles.begin(),piles.end());
        while(left<right){
            int mid=left+(right-left)/2;
            long long hours=0;
            for(int i=0;i<piles.size();i++){
                hours+=(piles[i]+mid-1)/mid;
            }
            if(hours<=h) right=mid;
            else left=mid+1;
        }
        return left;
    }
};

int main(){
    Solution obj;
    vector<int> piles={3,6,7,11};
    int h=8;
    cout<<obj.minEatingSpeed(piles,h);
    return 0;
}