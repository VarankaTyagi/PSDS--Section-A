#include <bits/stdc++.h>
using namespace std;

int digitSum(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int main() {
    int N;

    cout << "Enter N: ";
    cin >> N;

    vector<int> nums(N);

    cout << "Enter array elements: ";
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

            if (digitSum(nums[i]) == digitSum(nums[j])) {
                count++;
            }
        }
    }

    cout << "Number of special pairs: " << count << endl;

    return 0;
}