#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {

        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < t.length(); j++){
                if(s[i] == t[j]){
                    t.erase(j,1);
                    break;
                }
            }
        }

        return t[0];
    }
};

int main(){
    Solution obj;

    string s = "abcd";
    string t = "abcde";

    cout << obj.findTheDifference(s,t);

    return 0;
}