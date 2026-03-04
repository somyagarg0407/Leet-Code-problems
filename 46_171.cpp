#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string columnTitle) {
    long long pow = 1;
    long long sum = 0;
    int value;

    for(int i = columnTitle.length() - 1; i >= 0; i--) {
        value = columnTitle[i];
        sum += (value - 64) * pow;
        pow = pow * 26;
    }

    return sum;
}

int main() {
    string columnTitle;
    cin >> columnTitle;
    cout << titleToNumber(columnTitle);
    return 0;
}