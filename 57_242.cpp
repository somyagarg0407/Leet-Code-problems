#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s==t){
            return true;
        }

        else{
            return false;
        }
    }
};

int main(){

    string s, t;

    cout<<"Enter first string: ";
    cin>>s;

    cout<<"Enter second string: ";
    cin>>t;

    Solution obj;

    if(obj.isAnagram(s,t)){
        cout<<"Valid Anagram"<<endl;
    }
    else{
        cout<<"Not an Anagram"<<endl;
    }

    return 0;
}