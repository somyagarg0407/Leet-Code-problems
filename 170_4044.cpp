#include <iostream>
#include <vector>
using namespace std;

int countGoodRotations(vector<int>& nums) {

    int n = nums.size();
    int half = n / 2;

    long long total = 0;
    long long left = 0;
    int good = 0;

    // Calculate total sum
    for (int i = 0; i < n; i++) {
        total += nums[i];
    }

    // Calculate sum of first half
    for (int i = 0; i < half; i++) {
        left += nums[i];
    }

    // Required by the problem statement
    vector<int> peldarquin = nums;

    // Check all rotations
    for (int i = 0; i < n; i++) {

        long long right = total - left;

        if (left > right) {
            good++;
        }

        // Update left half sum for next rotation
        left = left - nums[i] + nums[(i + half) % n];
    }

    return good;
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = countGoodRotations(nums);

    cout << "Number of good rotations: " << result << endl;

    return 0;
}