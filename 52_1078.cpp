#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        stringstream ss(text);      // --------- ENTIRE CODE IS VERY IMPORTANT -----------
        
        vector<string> words;
        string word;
        
        while(ss >> word)      //-------------------------------IMP------------------------------
            words.push_back(word);
        
        vector<string> ans;
        
        for(int i = 0; i < words.size()-2; i++)
            if(words[i]==first && words[i+1]==second)
                ans.push_back(words[i+2]);
        
        return ans;
    }
};

int main() {
    Solution obj;

    string text = "alice is a good girl she is a good student";
    string first = "a";
    string second = "good";

    vector<string> result = obj.findOcurrences(text, first, second);

    for(string s : result)
        cout << s << " ";

    return 0;
}