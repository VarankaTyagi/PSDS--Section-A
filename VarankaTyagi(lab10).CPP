#include <bits/stdc++.h>
using namespace std;

int digit_sum(int num) {
    int total = 0;

    while (num > 0) {
        total += num % 10;
        num /= 10;
    }

    return total;
}

int solve() {
    int N;
    cin >> N;

    vector<int> nums(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (digit_sum(nums[i]) == digit_sum(nums[j])) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    cout << "Input:" << endl;

    int answer = solve();

    cout << "Output:" << endl;
    cout << answer << endl;

    return 0;
}