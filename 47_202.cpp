#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isHappy(int n) {
    int sum = 0;
    vector<int> digit;
    int rem = 0;
    unordered_set<int> s;   //------------------IMPORTANT----------------
    if(n == 1){
        return true;
    }

    while(n != 1){

        while(n != 0){
            rem = n % 10;
            digit.push_back(rem);
            n = n / 10;
        }

        for(int i = 0; i < digit.size(); i++){
            sum += digit[i] * digit[i];
        }

        digit.clear();

        n = sum;
        sum = 0;

        if(n == 1){
            return true;
            break;
        }

        if(s.count(n)){
            return false;
            break;
        }

        s.insert(n);
    }

    return 0;
}

int main() {
    int n;
    cin >> n;
    cout << isHappy(n);
    return 0;
}