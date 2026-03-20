#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int a = 0;
        int b = s.length();

        vector<int> ans;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'I'){
                ans.push_back(a);
                a++;
            }
            else if(s[i] == 'D'){
                ans.push_back(b);
                b--;
            }
        }

        ans.push_back(a);

        return ans;
    }
};

int main(){
    Solution obj;
    string s = "IDID";

    vector<int> result = obj.diStringMatch(s);

    for(int x : result){
        cout << x << " ";
    }

    return 0;
}