#include <iostream>
#include <vector>
using namespace std;

int addDigits(int num) {
    vector<int> digits;

    while (num >= 10) {

        while (num != 0) {
            digits.push_back(num % 10);
            num = num / 10;
        }

        num = 0;
        for (int i = 0; i < digits.size(); i++) {
            num += digits[i];
        }

        digits.clear();
    }

    return num;
}

int main() {
    int num;
    cin >> num;
    cout << addDigits(num);
    return 0;
}