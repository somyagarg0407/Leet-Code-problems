#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> a;
        vector<int> temp;

        for(int i=0;i<arr1.size();i++){
            temp.push_back(arr1[i]);
        }

        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr2[i] == arr1[j]) {
                    a.push_back(arr1[j]);
                    temp[j] = -1;
                }
            }
        }

        sort(temp.begin(), temp.end());

        for(int i=0;i<temp.size();i++){
            if(temp[i] >= 0){
                a.push_back(temp[i]);
            }
        }

        return a;
    }
};

int main(){

    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};

    Solution obj;
    vector<int> result = obj.relativeSortArray(arr1, arr2);

    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }

    return 0;
}