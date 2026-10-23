#include <iostream>
#include <string>
using namespace std;
string maxSumOfSquares(int num, int sum) {
    if (sum < 0 || sum > 9 * num)
        return "";
    string ans = "";
    while (sum >= 9) {
        ans += '9';
        sum -= 9;
    }
    if (sum > 0) {
        ans += char('0' + sum);
    }
    while (ans.size() < num) {
        ans += '0';
    }
    return ans;
}
int main() {
    int num, sum;
    cout << "Enter number of digits: ";
    cin >> num;
    cout << "Enter digit sum: ";
    cin >> sum;
    string result = maxSumOfSquares(num, sum);
    if (result == "")
        cout << "Invalid input or no valid number exists." << endl;
    else
        cout << "Result: " << result << endl;
    return 0;
}