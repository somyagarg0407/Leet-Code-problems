#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longestPalindrome(string s){

    vector<int> freq(52,0);

    for(char ch : s){
        if(ch >= 'a' && ch <= 'z')
            freq[ch-'a']++;
        else
            freq[ch-'A'+26]++;
    }

    int sum=0;
    int count=0;

    for(int i=0;i<52;i++){
        if(freq[i]%2==0)
            sum+=freq[i];
        else{
            sum+=freq[i]-1;
            count++;
        }
    }

    if(count>0) return sum+1;
    else return sum;
}

int main(){

    string s;
    cin >> s;

    cout << longestPalindrome(s);

    return 0;
}