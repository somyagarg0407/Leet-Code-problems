#include <iostream>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int fix = (n * (n + 1)) / 2;
        int sum = 0;
        int ans = -1;

        for(int i = 1; i <= n; i++){
            sum = (i * (i + 1)) / 2;

            if(sum == fix - sum + i){
                ans = i;
                sum = 0;
            }
        }

        return ans;
    }
};

int main(){
    Solution obj;

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Pivot Integer = " << obj.pivotInteger(n);

    return 0;
}