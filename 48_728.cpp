#include <iostream>
#include <vector>
using namespace std;

vector<int> selfDividingNumbers(int left, int right) {
    vector<int> num;
    vector<int> digits;
    vector<int> final;
    int count = 0;

    for (int i = left; i <= right; i++) {
        num.push_back(i);
    }

    for (int i = 0; i < num.size(); i++) {

        int temp = num[i];

        while (temp != 0) {
            digits.push_back(temp % 10);
            temp = temp / 10;
        }

        for (int j = 0; j < digits.size(); j++) {
            if (digits[j] != 0 && num[i] % digits[j] == 0) {
                count++;
            }
        }

        if (count == digits.size()) {
            final.push_back(num[i]);
        }

        count = 0;
        digits.clear();
    }

    return final;
}

int main() {
    int left, right;
    cin >> left >> right;

    vector<int> result = selfDividingNumbers(left, right);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}