#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;

        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){
                i++;
            }
            j++;
        }

        return i;
    }
};

int main() {

    vector<int> g = {1,2,3};   // greed factor of children
    vector<int> s = {1,1};     // cookie sizes

    Solution obj;
    int result = obj.findContentChildren(g, s);

    cout << "Number of content children: " << result;

    return 0;
}